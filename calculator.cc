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
  NUMBER, TK_HEX, TK_REG, TK_NEQ, TK_AND
};

Token tokens[32];
Token poland_stack[32];
Token poland_output[32];
int num_stack[32];

int nr_token;

int op_priority(int op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

void make_token(char *input) {
    for (char* iter = input; *iter != '\0'; iter++) {
        if (isdigit(*iter)) {
            int i;
            for (i = 0; isdigit(iter[i]); i++) {
                tokens[nr_token].str[i] = iter[i];
            }
            iter += i - 1;
            tokens[nr_token++].type = NUMBER;
        } else if (*iter != ' ') {
            tokens[nr_token++].type = *iter;
        }
    }
}

unsigned expr(int* step) {
    unsigned rst = 0;
    int num = 0, next = 0;
    int op = '+';

    for (int i = *step; i < nr_token; i++) {
        if (tokens[i].type == NUMBER) {
            sscanf(tokens[i].str, "%u", &next);
        } else if (tokens[i].type == '(') {
            i++;
            next = expr(&i);
        }
        switch (op) {
            case '+': {
                rst += num;
                num = next;
                break;
            }
            case '-': {
                rst += num;
                num = -next;
                break;
            }
            case '*': {
                num *= next;
                break;
            }
            case '/': {
                num /= next;
                break;
            }
        }
        
        if (++i < nr_token) {
            op = tokens[i].type;
            if (op == ')') {
                *step = i;
                break;
            }
        }
    }

    rst += num;
    return rst;
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
    int i;
    int val;
    int ans;
    int top1, top2;
    for (i = 0; i < poland_len; i++) {
        if (poland_output[i].type == NUMBER) {
            sscanf(poland_output[i].str, "%d", &val);
            num_stack[top++] = val;
        } else {
            top1 = num_stack[--top];
            top2 = num_stack[--top];
            switch (poland_output[i].type) {
                case '+': ans = top2 + top1; break;
                case '-': ans = top2 - top1; break;
                case '*': ans = top2 * top1; break;
                case '/': ans = top2 / top1; break;
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

int calculate(char* input) {
    make_token(input);
    return expr();
    // int step = 0;
    // return expr(&step);
}

int main() {
    char input[] = "( 723014127+ 585011881*2016025616/ 509096286)";
    // char input[] = "4 +3*(2- 1)";
    // char input[] = "4 + 1 * 3";
    cout << calculate(input);
    return 0;
}