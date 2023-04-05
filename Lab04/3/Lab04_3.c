#include <stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX_FILE_NAME 20


int main() {
    FILE *fpin;
    char file_name[MAX_FILE_NAME];
    int nr, nc, max_sum, dim, max_r, max_c;

    // Getting the file name
    printf("Please enter the file name:\n>>>\t");
    scanf("%s", file_name);
    fpin = fopen(file_name, "r");
    if (fpin == NULL){
        printf("Error opening the file.");
        return 1;
    }

    //defining the matrix
    fscanf(fpin, "%d %d", &nr, &nc);
    int mat[nr][nc];
    if (nc < 20 && nr < 20 ){
        for (int i = 0; i < nr; ++i){
            for (int j = 0; j < nc; ++j){
                fscanf(fpin, "%d", &mat[i][j]);
            }
        }
    }

    // prints the matrix
    printf("The Matrix:\n\n");
    for (int i = 0; i < nr; ++i){
        for (int j = 0; j <nc; ++j){
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\nPlease enter the dimension:\n>>>\t");
    scanf("%d", &dim);

    while (dim <= MIN(nr, nc) && dim){
        max_sum = -1;
        printf("\nThe square sub-matrices of dimension %d are:\n\n", dim);
        for (int r = 0; r <= nr - dim; r++){
            for (int c = 0 ; c <= nc -dim; c++){
                int sub_sum = 0;
                for (int p = r; p < r + dim; p++) {
                    for (int q = c; q < c + dim; q++) {
                        printf("%3d", mat[p][q]);
                        sub_sum += mat[p][q];
                    }
                    printf("\n");
                }
                if (sub_sum > max_sum) {
                    max_sum = sub_sum;
                    max_r = r;
                    max_c = c;
                }
                printf("\n");
            }
        }
        printf("The sub-matrix with maximum sum of elements (%d) is:\n\n", max_sum);
        for (int p = max_r; p < max_r + dim; p++) {
            for (int q = max_c; q < max_c + dim; q++) {
                printf("%3d", mat[p][q]);
            }
            printf("\n");
        }
        printf("--------------------------------------\n");
        // prompting the user for another dimension to get sub-matrices
        printf("Please enter the dimension (0 to end):\n>>>\t");
        scanf("%d", &dim);
        fflush(stdout);
    }


    fclose(fpin);

    return 0;
}
