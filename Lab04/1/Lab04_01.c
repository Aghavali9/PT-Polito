#include <stdio.h>
#define MAX_LENGTH 30

void subSequences(int v[], int n);
int prompt(int v[]);

void subSequences(int v[], int n){
    int sub_l = 0, max_s = -1, count = 0;

    for (int i=0; i < n; i++) {
        if (!v[i]) {
            sub_l = 0;
        }else{
            sub_l++;
        }
        if (sub_l > max_s)
            max_s = sub_l;
    }

    printf("Your Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%5d", v[i]);
    }
    printf("\n");
    printf("\nLongest None-Zero Sub-Sequence(s):\n");
    for (int i = 0; i <= n; i++){
        if (v[i] != 0)
            count++;
        else{
            if (count == max_s){

                for (int j = 0; j < count; j++){
                    printf("%5d", v[(i - count)+j]);
                }
                printf("\n\n");
            }
            count = 0;
        }
    }
}

int prompt(int v[]){
    int tmp, n = 0;
    while (n < MAX_LENGTH){

        printf("Enter integers (-1 to stop):\n>>> ");
        scanf("%d", &tmp);
        if (tmp == -1){
            break;
        }else{
            v[n] = tmp;
        }
        n++;
    }
    return n;
}

int main() {
    int num[MAX_LENGTH], n;

    n = prompt(num);
    /* Sample {1, 3, 4, 0, 1, 0, 9, 4, 2, 0}*/
    subSequences(num, n);
    
    return 0;
}
