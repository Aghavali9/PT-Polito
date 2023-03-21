#include <stdio.h>
int euler(int a, int b);

int euler(int int_1, int int_2){
    int gcf, remainder;

    while(!gcf){
        if (int_1 % int_2 != 0){
            remainder = int_1 % int_2;
            int_1 = int_2;
            int_2 = remainder;
        } else{
            gcf = int_2;
        }
    }
    return gcf;
}

int main() {
    int a, b, gcf;

    printf("Please enter two integers:\n");
    if (scanf("%d %d", &a, &b) == 2){
        if (a > b){
            gcf = euler(a, b);
        }else{
            gcf = euler(b, a);
        }
    }
    printf("The GCF of %d and %d is: %d", a, b, gcf);

    return 0;
}
