#include <stdio.h>

int main() {
    char oper;
    float op1, op2, result;

    printf("What do you want to do?\n(+, -, * or /)\n>>> ");
    oper = getchar();

    printf("Enter two numbers\n>> ");
    scanf("%f %f", &op1, &op2);

    switch (oper) {
        case '+': {
            result = op1 + op2;
            printf("%c %.2f %.2f = %.2f", oper, op1, op2, result);
            break;
        }
        case '-':{
            result = op1 - op2;
            printf("%c %.2f %.2f = %.2f", oper, op1, op2, result);
            break;
        }

        case '*':{
            result = op1 * op2;
            printf("%c %.2f %.2f = %.2f", oper, op1, op2, result);
            break;
        }
        case '/':{
            if (op2 ==0){
                printf("DIVISION BY ZERO");
                return 1;
            }
            else{
                result = op1 / op2;
                printf("%c %.2f %.2f = %.2f", oper, op1, op2, result);
                break;
            }
        }
        default:
            printf("INVALID OPERATOR");
            return 1;
    }

    return 0;
}
