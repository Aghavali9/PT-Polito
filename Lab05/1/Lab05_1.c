#include <stdio.h>
#define MAX_NAME 20
#define MAXN 20

int main() {
   FILE *fpin;
   char file_name[MAX_NAME];
   int n, m, i, j, k, r, max_sum = -1, sub_sum;

    printf("Please enter the file name:\n>>>\t");
    scanf("%s", file_name);

   fpin = fopen(file_name, "r");
    if (file_name == NULL){
        printf("Error opening the file.");
        return 1;
    }
    fscanf(fpin, "%d %d", &n, &m);
    if (n > MAXN || m > MAXN){
        printf("Exceeding limits");
        return 1;
    }
    int mat[n][m];
    for (i = 0; i < n; ++i){
        for (j = 0; j < m; ++j){
            fscanf(fpin, "%d", &mat[i][j]);
        }
    }
    printf("%d teams and %d days results:\n\n", n, m);
    for (i = 0; i < n; ++i){
        for (j = 0; j <m; ++j){
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("--------------------------\n");
    for (k =0; k < m; ++k){
        printf("Day %d Leader:\n\n", k+1);
        for (i = 0; i < n; ++i){
            sub_sum = 0;
            for (j = 0; j <= k; ++j){
                sub_sum += mat[i][j];
            }
            if (sub_sum > max_sum){
                max_sum = sub_sum;
                r = i;
            }

        }
        printf("Team %d , Score: %d\n", r+1, max_sum);
        printf("\n");

    }

    fclose(fpin);
    return 0;
}
