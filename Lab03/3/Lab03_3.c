#include <stdio.h>
#define FILE_NAME "../numbers.txt"

int is_valid (int a, int b, int c);

int is_valid (int a, int b, int c){
    int flag = 0;

    if (b != 0) {
        if (a + b == c || a - b == c || a * b == c || a / b == c || a * b == c) {
            flag = 1;
        }
    }else if (a + b == c || a - b == c || a * b == c || a * b == c) {
        flag = 1;
    }

    return flag;
}

int main() {
    FILE *fpin;
    int d_2, d_1, d, count = 0, max_d = -2147483647, min_d = 2147483647;

    fpin = fopen(FILE_NAME, "r");

    if (fpin == NULL){
        printf("Error opening the file.");
        return 1;
    }

    fscanf(fpin, "%d" , &d_2);
    fscanf(fpin, "%d" , &d_1);

    while (!feof(fpin)){
        if (d_2 > max_d){
            max_d = d_2;
        }
        if (d_2 < min_d){
            min_d = d_2;
        }
        fscanf(fpin, "%d" , &d);

        if (!is_valid(d_2, d_1, d)){
            count++;
            continue;
        }else{
            d_2 = d_1;
            d_1 = d;
        }
    }
    if (count == 0){
        printf("Sequence of numbers is valid\n");
    }else {
        printf("# of discarded values : %d\n", count);
    }
    printf("Max Value: %d\n", max_d);
    printf("Min Value: %d\n", min_d);

    return 0;
}
