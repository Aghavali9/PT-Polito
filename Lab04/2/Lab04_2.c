#include <stdio.h>
#define maxN 30

void rotate(int v[maxN], int n, int p, int dir);

void rotate(int v[maxN], int n, int p, int dir){

    int tmp[n];
    for (int i = 0; i < n; ++i){
        tmp[(i + n - p * dir) % n] = v[i];
    }
    for (int i = 0; i < n; ++i){
        v[i] = tmp[i];
    }
}

int main() {
    int n; // getting the dimension
    printf("Enter n:\t");
    scanf("%d", &n);
    if (n > maxN){
        printf("ERROR");
        return 1;
    }
    int v[n]; // creating the vector
    printf("Enter the elements:\t");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    printf("The elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    int p, dir; // getting the direction and
    printf("Enter positions to rotate:\t");
    scanf("%d", &p);
    while(p){
        printf("Enter direction (1 to left) (-1 to right):\t");
        scanf("%d", &dir);
        rotate(v,n,p,dir);
        printf("Rotated vector: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
        printf("Enter p (0 to stop):\t");
        scanf("%d", &p);
    }

    return 0;
}
