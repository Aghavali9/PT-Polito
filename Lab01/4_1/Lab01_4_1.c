/*
 * Write a C program that is able to compute either the area of a circle or of a square, based
 * on the choice and inputs of the user. The user is requested to type a set of characters and
 * numbers from keyboard, in a specific order. The first character should be S for square or C for
 * circle. In case it is a square, the user can decide whether the area should be computed given
 * the value of the diagonal or of the side of the square, by specifying its respective length after
 * the character D or S. In case it is a circle, the user can decide whether the area should be
 * computed given the value of the diameter or of the radius by specifying its respective length
 * after the character D or R, respectively. All the values inserted by the user should be integer,
 * the computed area should be a float.
 * */
#include <stdio.h>
#define PI 3.14

int main() {
    char shape, dim_name;
    float dim, area;

    printf("Square or Circle (S or C)\nIn case of a Square choose Diagonal or Side (D or S)\n"
           "In case of a Circle choose Radius or Diameter (R or D)\n"
           "Enter the value of the chosen dimension.\ni.e: (S S 2 is a Square with Sides of length 2)\n\t>>> ");
    scanf("%c %c %f", &shape, &dim_name, &dim);

    switch (shape) {
        case 'S':
            switch (dim_name) {
                case 'S': {
                    area = dim * dim;
                    printf("Area of a Square with Sides of %.2f is %.2f.", dim, area);
                    break;
                }
                case 'D': {
                    area = dim * dim / 2;
                    printf("Area of a Square with Diagonal of %.2f is %.2f.", dim, area);
                    break;
                }
                default:
                    printf("Incorrect inputs");
                    return 1;

            }
            break;
        case 'C':
            switch (dim_name) {
                case 'R': {
                    area = PI * dim * dim;
                    printf("Area of a Circle with Radius of %.2f is %.2f.", dim, area);
                    break;
                }
                case 'D': {
                    area = PI * dim * dim / 4;
                    printf("Area of a Circle with Diameter of %.2f is %.2f.", dim, area);
                    break;
                }
                default:
                    printf("Incorrect inputs");
                    return 1;
            }
            break;
        default:
            printf("Incorrect inputs");
            return 1;
    }


    return 0;
}
