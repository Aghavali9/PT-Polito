#include <stdio.h>

int main() {
    FILE *fp_read, *fp_write_odd, *fp_write_even;
    char file_string[100], name[20];
    int counter = 0;
    if ((fp_read = fopen("../Bronte.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fp_write_odd = fopen("../Output_odd.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 2;
    }
    if ((fp_write_even = fopen("../Output_even.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 3;
    }
    printf("What's your name?");
    gets(name);
    while (!feof(fp_read)) {
        counter++;
        if (counter%2==0) {
            fscanf(fp_read, "%s", file_string);
            /* fscanf is used to read formatted input from a file. It takes two or more parameters:
            - a pointer to the FILE stream to read from
            - a format string that specifies the expected format of the input, and one or more pointers
             to variables to store the read values.
            fscanf reads characters from the file according to the format string,
            and stores the values in the corresponding variables.
            */
            if (!feof(fp_read)) {
                printf("%s\nI am reading:\n%s\n\n", name, file_string);
                fprintf(fp_write_even, "%s", file_string);
            }
        }
        else {
            fgets(file_string, 100, fp_read);
            /* fgets is used to read a line of text from a file. It takes three parameters:
            - a pointer to a character array to store the read line
            - the maximum number of characters to read (including the terminating newline character)
            - a pointer to the FILE stream to read from.
            fgets reads characters from the file until it reaches the maximum number of characters specified,
            or until it encounters a newline character (\n). It then stores the characters, including the newline character,
            in the character array and adds a null terminator (\0) at the end.
            */
             if (!feof(fp_read)) {
                puts(name);
                puts("I am reading:");
                puts(file_string);
                fputs(file_string, fp_write_odd);
            }
        }
    }
    fclose(fp_read);
    fclose(fp_write_even);
    fclose(fp_write_odd);
    return 0;
}
