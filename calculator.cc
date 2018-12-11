#include <iostream>
#include <cstdlib>

using namespace std;

struct {
    int type;
    char str[30];
}tokens[32];

enum {NUMBER, EQ};

int nr_token;

void make_token(char *input) {
    for (char* iter = input; *iter != '\0'; iter++) {
        if (isdigit(*iter)) {
            int i;
            for (i = 0; isdigit(iter[i]); i++) {
                tokens[nr_token].str[i] = iter[i];
            }
            iter += i - 1;
            tokens[nr_token++].type = NUMBER;
        } else if (iter[0] == '=' && iter[1] == '=') {
            tokens[nr_token++].type = EQ;
        } else if (*iter != ' ') {
            tokens[nr_token++].type = *iter;
        }
    }
}

int expr(int* step) {
    int rst = 0;
    int num = 0, next = 0;
    int op = '+';

    for (int i = *step; i < nr_token; i++) {
        if (tokens[i].type == NUMBER) {
            next = atoi(tokens[i].str);
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
        op = tokens[++i].type;
        if (op == ')') {
            *step = i;
            break;
        }
    }

    rst += num;
    return rst;
}

int calculate(char* input) {
    make_token(input);
    int step = 0;
    return expr(&step);
}

int main() {
    char input[] = "1+ 2*((2 +4)*5 / (1+2)) /11";
    // char input[] = "4 +3*(2- 1)";
    cout << calculate(input);
    return 0;
}