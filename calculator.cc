#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct {
    int type;
    char str[30];
} Token;

enum {
  TK_NOTYPE = 256, TK_EQ,

  /* TODO: Add more token types */
  NUMBER, TK_HEX, TK_REG, TK_NEQ, TK_AND, TK_DEFER
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

Token tokens[32];
Token poland_stack[32];
Token poland_output[32];
int num_stack[32];

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
        case TK_DEFER:
        case TK_REG: return 5;
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
            i += j - 1;
            tokens[nr_token++].type = NUMBER;
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

int cal_poland(int poland_len) {
    int top = 0;
    int ans = 0;
    int i;
    int val;
    int top1, top2;
    for (i = 0; i < poland_len; i++) {
        if (poland_output[i].type == NUMBER) {
            sscanf(poland_output[i].str, "%d", &val);
            num_stack[top++] = val;
        } else if (poland_output[i].type == TK_HEX) {
            sscanf(poland_output[i].str, "%x", &val);
            num_stack[top++] = val;
        } else if (poland_output[i].type == TK_REG) {
            num_stack[top++] = reg_value(poland_output[i].str + 1);
        } else {
            top1 = num_stack[--top];
            if (poland_output[i].type == TK_DEFER) {
                ans = top1 * 2;
            } else {
                // binary op
                top2 = num_stack[--top];
                switch (poland_output[i].type) {
                    case '+': ans = top2 + top1; break;
                    case '-': ans = top2 - top1; break;
                    case '*': ans = top2 * top1; break;
                    case '/': ans = top2 / top1; break;
                    case TK_AND: ans = top2 && top1; break;
                    case TK_NEQ: ans = top2 != top1; break;
                    case TK_EQ:  ans = top2 == top1; break;
                }
            }
            
            num_stack[top++] = ans;
        }
    }
    return num_stack[top-1];
}

unsigned expr() {
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

unsigned calculate(char* input) {
    make_token(input);

    for (int i = 0; i < nr_token; i++) {
        if (tokens[i].type == '*') {
            if (i == 0) {
                tokens[i].type = TK_DEFER;
            }
            switch (tokens[i-1].type) {
                case '+': case '-': case '*': case '/':
                case TK_AND: case TK_NEQ: case TK_EQ: {
                    tokens[i].type = TK_DEFER;
                }
            }
        }
    }

    return expr();
    // int step = 0;
    // return expr(&step);
}

int main() {
    // char input[] = "( 723014127+ 585011881*2016025616/ 509096286)";
    char input[] = "4 +3*(2+ 1) == 0xd && $ax == 0";
    // char input[] = "$ax";
    cout << calculate(input);
    return 0;
}