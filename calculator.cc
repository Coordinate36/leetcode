#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct {
    int type;
    char str[30];
} Token;

typedef struct {
    int type;
    union {
        int int_;
        double double_;
    };
} Operand;

enum {
  TK_NOTYPE = 256, TK_EQ,

  /* TODO: Add more token types */
  NUMBER, TK_HEX, TK_REG, TK_NEQ, TK_AND, TK_DEFER, TK_NEG, DECIMAL
};

enum { R_EAX, R_ECX, R_EDX, R_EBX, R_ESP, R_EBP, R_ESI, R_EDI };
enum { R_AX, R_CX, R_DX, R_BX, R_SP, R_BP, R_SI, R_DI };
enum { R_AL, R_CL, R_DL, R_BL, R_AH, R_CH, R_DH, R_BH };

const char* reg_ls[] = {"eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"};
const char* reg_ws[] = {"ax", "cx", "dx", "bx", "sp", "bp", "si", "di"};
const char* reg_bs[] = {"al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"};
int grp_w[] = {0, 1, 2, 3, 4, 5, 6, 7};
int grp_l[] = {8, 9, 10, 11, 12, 13, 14, 15};
int grp_b[] = {20, 21, 22, 23, 24, 25, 26, 27};

const int TOKEN_NUM = 255;

Token tokens[TOKEN_NUM];
Token poland_stack[TOKEN_NUM];
Token poland_output[TOKEN_NUM];
Operand num_stack[TOKEN_NUM];

int nr_token;

int op_priority(int op) {
    switch (op) {
        case TK_AND: return 1;
        case TK_EQ:
        case TK_NEQ: return 2;
        case '+':
        case '-': return 3;
        case '*':
        case '/': return 4;
        case TK_NEG:
        case TK_DEFER: return 5;
        default: return 0;
    }
}

void make_token(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '0' && input[i+1] == 'x') {
            i += 2;
            int j;
            for (j = 0; isdigit(input[i+j]) || (input[i+j] >= 'a' && input[i+j] <= 'f'); j++) {
                tokens[nr_token].str[j] = input[i+j];
            }
            i += j - 1;
            tokens[nr_token++].type = TK_HEX;
        } else if (isdigit(input[i])) {
            int j;
            for (j = 0; isdigit(input[i+j]); j++) {
                tokens[nr_token].str[j] = input[i+j];
            }
            if (input[i+j] == '.') {
                tokens[nr_token].str[j] = input[i+j];
                for (j++; isdigit(input[i+j]); j++) {
                    tokens[nr_token].str[j] = input[i+j];
                }
                tokens[nr_token++].type = DECIMAL;
            } else {
                tokens[nr_token++].type = NUMBER;
            }
            i += j - 1;
        } else if (input[i] == '=' && input[i+1] == '=') {
            i++;
            tokens[nr_token++].type = TK_EQ;
        } else if (input[i] == '&' && input[i+1] == '&') {
            i++;
            tokens[nr_token++].type = TK_AND;
        } else if (input[i] == '!' && input[i+1] == '=') {
            i++;
            tokens[nr_token++].type = TK_NEQ;
        } else if (input[i] == '$') {
            int j;
            for (j = 0; input[i+j] == '$' || (input[i+j] >= 'a' && input[i+j] <= 'z'); j++) {
                tokens[nr_token].str[j] = input[i+j];
            }
            i += j - 1;
            tokens[nr_token++].type = TK_REG;
        } else if (input[i] != ' ') {
            tokens[nr_token++].type = input[i];
        }
    }
}

int reg_value(char* reg) {
    int i;
    for (i = 0; i < 8; i++) {
        if (strcmp(reg, reg_ls[i]) == 0) {
            return grp_l[i];
        } else if (strcmp(reg, reg_ws[i]) == 0) {
            return grp_w[i];
        } else if (strcmp(reg, reg_bs[i]) == 0) {
            return grp_b[i];
        }
    }
    return -1;
}

int make_poland() {
    int top = 0;
    int poland_len = 0;
    int i;
    for (i = 0; i < nr_token; i++) {
        switch (tokens[i].type) {
            case '(': {
                poland_stack[top++] = tokens[i];
                break;
            }
            case ')': {
                while (top > 0 && poland_stack[--top].type != '(') {
                    poland_output[poland_len++] = poland_stack[top];
                }
                break;
            }
            case DECIMAL:
            case TK_REG:
            case TK_HEX:
            case NUMBER: {
                poland_output[poland_len++] = tokens[i];
                break;
            }
            default: {
                if (op_priority(tokens[i].type) > op_priority(poland_stack[top-1].type)) {
                    poland_stack[top++] = tokens[i];
                } else {
                    while (top > 0 && op_priority(tokens[i].type) <= op_priority(poland_stack[top-1].type)) {
                        poland_output[poland_len++] = poland_stack[--top];
                    }
                    poland_stack[top++] = tokens[i];
                }
            }
        }
    }
    while (top > 0) {
        poland_output[poland_len++] = poland_stack[--top];
    }

    return poland_len;
}

Operand cal_poland(int poland_len) {
    int top = 0;
    Operand ans;
    Operand val;
    Operand top1, top2;
    int i;
    for (i = 0; i < poland_len; i++) {
        if (poland_output[i].type == NUMBER) {
            val.type = NUMBER;
            sscanf(poland_output[i].str, "%d", &val.int_);
            num_stack[top++] = val;
        } else if (poland_output[i].type == TK_HEX) {
            val.type = NUMBER;
            sscanf(poland_output[i].str, "%x", &val.int_);
            num_stack[top++] = val;
        } else if (poland_output[i].type == DECIMAL) {
            val.type = DECIMAL;
            sscanf(poland_output[i].str, "%lf", &val.double_);
            num_stack[top++] = val;
        } else if (poland_output[i].type == TK_REG) {
            val.type = NUMBER;
            val.int_ = reg_value(poland_output[i].str + 1);
            num_stack[top++] = val;
        } else {
            top1 = num_stack[--top];
            ans.type = top1.type;
            if (poland_output[i].type == TK_DEFER) {
                ans.int_ = top1.int_ * 2;
            } else if (poland_output[i].type == TK_NEG) {
                if (top1.type == NUMBER) {
                    ans.int_ = -top1.int_;
                } else {
                    ans.double_ = -top1.double_;
                }
            } else {
                // binary op
                top2 = num_stack[--top];
                if (top2.type == DECIMAL) {
                    ans.type = DECIMAL;
                }
                if (ans.type == NUMBER) {
                    switch (poland_output[i].type) {
                        case '+': ans.int_ = top2.int_ + top1.int_; break;
                        case '-': ans.int_ = top2.int_ - top1.int_; break;
                        case '*': ans.int_ = top2.int_ * top1.int_; break;
                        case '/': ans.int_ = top2.int_ / top1.int_; break;
                        case TK_AND: ans.int_ = top2.int_ && top1.int_; break;
                        case TK_NEQ: ans.int_ = top2.int_ != top1.int_; break;
                        case TK_EQ:  ans.int_ = top2.int_ == top1.int_; break;
                    }
                } else {
                    switch (poland_output[i].type) {
                        case '+': ans.double_ = (top2.type == NUMBER ? top2.int_: top2.double_) + (top1.type == NUMBER ? top1.int_: top1.double_); break;
                        case '-': ans.double_ = (top2.type == NUMBER ? top2.int_: top2.double_) - (top1.type == NUMBER ? top1.int_: top1.double_); break;
                        case '*': ans.double_ = (top2.type == NUMBER ? top2.int_: top2.double_) * (top1.type == NUMBER ? top1.int_: top1.double_); break;
                        case '/': ans.double_ = (top2.type == NUMBER ? top2.int_: top2.double_) / (top1.type == NUMBER ? top1.int_: top1.double_); break;
                        case TK_AND: ans.double_ = (top2.type == NUMBER ? top2.int_: top2.double_) && (top1.type == NUMBER ? top1.int_: top1.double_); break;
                        case TK_NEQ: ans.double_ = (top2.type == NUMBER ? top2.int_: top2.double_) != (top1.type == NUMBER ? top1.int_: top1.double_); break;
                        case TK_EQ:  ans.double_ = (top2.type == NUMBER ? top2.int_: top2.double_) == (top1.type == NUMBER ? top1.int_: top1.double_); break;
                    }
                }
            }
            
            num_stack[top++] = ans;
        }
    }
    return num_stack[top-1];
}

Operand expr() {
    int poland_len = make_poland();
    return cal_poland(poland_len);   
}

bool check_parentheses(int begin, int end) {
    int cnt = 0;
    int i;
    for (i = begin; i != end; i++) {
        if (tokens[i].type == '(') {
            cnt++;
        } else if (tokens[i].type == ')') {
            cnt--;
        }
    }
    return cnt == 0;
}

Operand calculate(char* input) {
    make_token(input);

    for (int i = 0; i < nr_token; i++) {
        if (tokens[i].type == '*') {
            if (i == 0) {
                tokens[i].type = TK_DEFER;
            }
            switch (tokens[i-1].type) {
                case '+': case '-': case '*': case '/': case '(':
                case TK_AND: case TK_NEQ: case TK_EQ: {
                    tokens[i].type = TK_DEFER;
                }
            }
        } else if (tokens[i].type == '-') {
            if (i == 0) {
                tokens[i].type = TK_NEG;
            }
            switch (tokens[i-1].type) {
                case '+': case '-': case '*': case '/': case '(':
                case TK_AND: case TK_NEQ: case TK_EQ: {
                    tokens[i].type = TK_NEG;
                }
            }
        }
    }

    return expr();
}

int main() {
    // char input[] = "( 723014127+ 585011881*2016025616/ 509096286)";
    char input[] = "( 626516348)+ 505496690/ 826252910";
    // char input[] = "(1.2+(3*2) +(($eax-$eax) +(*$eip-1**$eip)+(0x5--5+ *0x100005 - *0x100005))*4)";
    Operand rst = calculate(input);
    cout << rst.type << endl;
    cout << rst.int_ << endl;
    cout << (rst.type == NUMBER ? rst.int_: rst.double_) << endl;
    return 0;
}