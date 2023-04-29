#include <stdio.h>
#include <string.h>
#define MAXN 30
#define MAXC 100

void rotate_row(int matrix[MAXN][MAXN], int row, char direction[], int locations, int nc) {
    int temp[MAXN];
    for (int i = 0; i < nc; i++) {
        temp[i] = matrix[row][i];
    }

    if (strcmp(direction, "right") == 0) {
        for (int i = 0; i < nc; i++) {
            matrix[row][(i + locations) % nc] = temp[i];
        }
    } else if (strcmp(direction, "left") == 0) {
        for (int i = 0; i < nc; i++) {
            matrix[row][(i - locations + nc) % nc] = temp[i];
        }
    }

}

void rotate_column(int matrix[MAXN][MAXN], int column, char direction[], int locations, int nr) {
    int temp[MAXN];
    for (int i = 0; i < nr; i++) {
        temp[i] = matrix[i][column];
    }
    if (strcmp(direction, "up") == 0) {
        for (int i = 0; i < nr; i++) {
            matrix[(i - locations + nr) % nr][column] = temp[i];
        }
    } else if (strcmp(direction, "down") == 0) {
        for (int i = 0; i < nr; i++) {
            matrix[(i + locations) % nr][column] = temp[i];
        }
    }
}

void print_matrix(int matrix[MAXN][MAXN], int nr, int nc) {
    printf("-------------\n");
    for (int i = 0; i < nr; ++i){
        for (int j = 0; j <nc; ++j){
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAXN][MAXN], c, flag_e = 1;
    char fileName[20];
    printf("Enter file name:\n>>> ");
    scanf("%s", fileName);
    while ((c = getchar()) != '\n');
    FILE *fpin = fopen(fileName, "r");
    if (fpin == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    int nr, nc;
    fscanf(fpin, "%d %d", &nr, &nc);
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            fscanf(fpin, "%d", &matrix[i][j]);
        }
    }
    fclose(fpin);
    printf("-------------\n");
    for (int i = 0; i < nr; ++i){
        for (int j = 0; j <nc; ++j){
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    char command[100];
    while (flag_e) {
        printf("Enter command:\n>>> ");
        fgets(command, MAXC, stdin);
        /*scanf("%[^\n]", command);*/ // does not work
        /*strcat(command, "\n");*/
        char selector[10], direction[10];
        int index, locations;
        sscanf(command, "%s %d %s %d", selector, &index, direction, &locations);
        if (strcmp(selector, "end") == 0){
            flag_e = 0;
        }

        if (strcmp(selector, "row") == 0) {
            if (index > 0 && index < nr){
                if (strcmp(direction, "right") == 0 || strcmp(direction, "left") == 0){
                    rotate_row(matrix, index - 1, direction, locations, nc);
                    print_matrix(matrix, nr, nc);
                }else{
                    printf("Invalid command1\nPress enter to continue");
                    while ((c = getchar()) != '\n'); //  essential for clearing the buffer.
                    puts("");
                    continue;
                }
            }
        } else if (strcmp(selector, "column") == 0) {
            if (index > 0 && index < nc){
                if (strcmp(direction, "down") == 0 || strcmp(direction, "up") == 0){
                    rotate_column(matrix, index - 1, direction, locations, nr);
                    print_matrix(matrix, nr, nc);
                }else{
                    printf("Invalid command2\nPress enter to continue");
                    puts("");
                    while ((c = getchar()) != '\n');
                    continue;
                }
            }
        }else if(flag_e == 0){
            printf("Gracefully ended.");
        }
        else{
            printf("Invalid command3\nPress enter to continue");
            puts("");
            while ((c = getchar()) != '\n');
            continue;
        }

    }

    return 0;
}
