#include <stdio.h>

int main() {
    FILE *fp_out;
    FILE *fp_in;
    char op;
    float op1, op2, result;

    if ((fp_in = fopen("../Input.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fp_out = fopen("../Output.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 2;
    }

    while (!feof(fp_in)) {

        fscanf(fp_in, "%s %f %f", &op, &op1, &op2);

        switch (op) {
            case '+': {
                result = op1 + op2;
                fprintf(fp_out, "%c %.2f\n", op, result);
                break;
            }
            case '-': {
                result = op1 - op2;
                fprintf(fp_out, "%c %.2f\n", op, result);
                break;
            }

            case '*': {
                result = op1 * op2;
                fprintf(fp_out, "%c %.2f\n", op, result);
                break;
            }
            case '/': {
                if (op2 == 0) {
                    printf("DIVISION BY ZERO");
                    return 1;
                } else {
                    result = op1 / op2;
                    fprintf(fp_out, "%c %.2f\n", op, result);
                    break;
                }
            }
            default:
                printf("INVALID OPERATOR");
                return 1;
        }
    }


    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
