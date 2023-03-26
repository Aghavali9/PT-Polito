#include <stdio.h>
#include <stdlib.h>

int compressing(FILE *fin, FILE *fout);
int decompressing(FILE *fin, FILE *fout);

int compressing(FILE *fin, FILE *fout){
    char current_char, previous_char;
    int current_char_count = 0;
    long printed_char_count = 0;
    int i, j;
  
    previous_char = fgetc(fin);
    do { // Iterate over each character in the file
        current_char = fgetc(fin);
        if (current_char == previous_char){
            current_char_count++;
        }
        else{
            if (current_char_count < 2){
                fprintf(fout,"%c", previous_char);
            }else{
                if (current_char_count > 9){
                    i = current_char_count / 9;
                    int rem = current_char_count % 9;
                    for (j = 1; j <= i; j++){
                        fprintf(fout, "%c$9", previous_char);
                    }
                    fprintf(fout,"%c$%d", previous_char, rem-1);

                }else {
                    fprintf(fout, "%c$%d", previous_char, current_char_count);
                }
            }
            current_char_count = 0;
        }
        previous_char = current_char;
        printed_char_count++;
    } while (current_char != EOF);
    printf("\nFile compressed successfully.\n");
    // counting the printed characters; \n is included
    printed_char_count = ftell(fout);
    if (printed_char_count == -1) {
        printf("Error: Could not determine position in file.\n");
        return 1;
    }
    printf("%ld characters were printed", printed_char_count);
    return 0;
}


int decompressing(FILE *fin, FILE *fout){
    char current_char, next_char;
    int repetitions = 0;
    long printed_char_count = 0;
    int i;

    current_char = fgetc(fin);
    do {
        next_char = fgetc(fin);
        if (next_char == '$') {
            repetitions = fgetc(fin) - '0';
            /* When you read a character from a file using fgetc, it returns the ASCII value of the character.
               The ASCII values of the digits 0 to 9 are in the range 48 to 57.
               By subtracting the ASCII value of '0' (which is 48) from the ASCII value of the digit character, you get the integer value of the digit.
            */
            for (i = 1; i <= repetitions; i++) {
                fprintf(fout, "%c", current_char);
            }
        } else {
            fprintf(fout, "%c", current_char); // Write character to output file
        }
    } while ((current_char = fgetc(fin)) != EOF); // Iterate over each character in the file

    printf("\nFile decompressed successfully.\n");
    // counting the printed characters; \n is included
    printed_char_count = ftell(fout);
    if (printed_char_count == -1) {
        printf("Error counting the characters in file.\n");
        return 1;
    }
    printf("%ld characters were printed", printed_char_count);

    return 0;
}


int main() {
    FILE *source_file, *compressed_file, *decompressed_file;
    char source_file_name[] = "source.txt";
    char compressed_file_name[] = "compressed.txt";
    char decompressed_file_name[] = "decompressed.txt";
    char choice;

    // Choosing the operation mode; Compression or Decompression
    printf("Enter the mode: Compression of Decompression (C or D):\n");
    scanf("%c", &choice);
    switch (choice) {
        case 'D': {
            compressed_file = fopen(compressed_file_name, "r");
            decompressed_file = fopen(decompressed_file_name, "w");
            if (compressed_file == NULL) {
                printf("Error writing file %s\n", compressed_file_name);
                exit(2);
            }
            if (decompressed_file == NULL){
                printf("Error writing file %s\n", decompressed_file_name);
                exit(3);
            }
            decompressing(compressed_file,decompressed_file);
            break;
        }
        case 'C':{
            source_file = fopen(source_file_name, "r");
            compressed_file = fopen(compressed_file_name, "w");
            if (source_file == NULL) {
                printf("Error opening file %s\n", source_file_name);
                exit(1);
            }
            if (compressed_file == NULL) {
                printf("Error writing file %s\n", compressed_file_name);
                exit(2);
            }
            compressing(source_file, compressed_file);
        break;
        }
        default:{
            printf("Incorrect inputs");
            return 1;
        }
    }
    fclose(source_file);
    fclose(compressed_file);
    fclose(decompressed_file);


    return 0;
}
