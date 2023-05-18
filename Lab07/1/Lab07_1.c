#include <stdio.h>
#define MAX_DIM 50
#define FILE_NAME "../input.txt"

typedef struct {
    int x;
    int y;
    int area;
    int height;
    int width;
}t_block;

void check_block(int matrix[MAX_DIM][MAX_DIM], int nr, int nc,t_block *max_height_block, t_block  *max_width_block, t_block *max_area_block);

void check_block(int matrix[][MAX_DIM], int nr, int nc,t_block *max_height_block, t_block  *max_width_block, t_block *max_area_block){

    int i, j;
    int w, h;
    int area;
    int max_w_local = -1;
    int max_h_local = -1;
    int max_area_local = -1;

    for (i = 0; i < nr; i++) {
        w = 0;
        h = 0;
        area = 0;
        for (j = 0; j < nc; j++) {
            if (matrix[i][j] == 1) {
                h = 1;
                w++;
                area++;
                if (matrix[i][j + 1] == 0 || j + 1 >= nc) {
                        int t = i;
                        while (matrix[t+1][j] == 1 && t < nr -1) {
                            h++;
                            area = area + w;
                            t++;
                        }
                }
            }else{
                w = 0;
                h = 0;
                area = 0;
            }
            if (w > max_w_local) {
                max_w_local = w;
                max_width_block-> x = i;
                max_width_block-> y = j - w + 1;
                max_width_block-> width = max_w_local;
                max_width_block-> height = h;
                max_width_block-> area = area;
            }
            if (h > max_h_local) {
                max_h_local = h;
                max_height_block-> x = i;
                max_height_block-> y = j - w + 1;
                max_height_block-> width = w;
                max_height_block-> height = max_h_local;
                max_height_block-> area = area;
            }
            if (area > max_area_local) {
                max_area_local = area;
                max_area_block-> x = i;
                max_area_block-> y = j - w + 1;
                max_area_block-> width = w;
                max_area_block-> height = h;
                max_area_block-> area = max_area_local;
            }
/*
            printf("i=%d, j=%d, w=%d, h=%d, area=%d\n", i, j, w, h, area); control test
*/
        }
    }
}


int main() {
    FILE *fpin;
    int nr, nc;
    int matrix[MAX_DIM][MAX_DIM];
    t_block max_height_block, max_width_block, max_area_block;

    fpin = fopen(FILE_NAME, "r");
    if (fpin == NULL) {
        printf("Error opening file\n");
    }

    fscanf(fpin, "%d %d", &nr, &nc);

    if (nr > MAX_DIM || nc > MAX_DIM) {
        printf("Dimensions too big\n");
        return 1;
    }


    int i, j;
    for (i = 0; i < nr; i++) {
        for (j = 0; j < nc; j++) {
            fscanf(fpin, "%d", &matrix[i][j]);
        }
    }
    fclose(fpin);

    printf("Matrix:\n");
    for (i = 0; i < nr; i++) {
        for (j = 0; j < nc; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    //TODO: code here

    check_block(matrix, nr, nc, &max_height_block, &max_width_block, &max_area_block);
    printf("Max height region: upper left corner=(%d, %d), width= %d, height= %d, area= %d\n", max_height_block.x, max_height_block.y, max_height_block.width, max_height_block.height, max_height_block.area);
    printf("Max width region: upper left corner=(%d, %d), width= %d, height= %d, area= %d\n", max_width_block.x, max_width_block.y, max_width_block.width, max_width_block.height, max_width_block.area);
    printf("Max area region: upper left corner=(%d, %d), width= %d, height= %d, area= %d\n", max_area_block.x, max_area_block.y, max_area_block.width,max_area_block.height, max_area_block.area);



    return 0;
}
