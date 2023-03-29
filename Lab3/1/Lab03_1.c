#include <stdio.h>
#include <ctype.h>
#define FIN "input.txt"
#define FOUT "output.txt"


int main() {
    FILE *fp_in, *fp_out;
    int count = 0, spaces;
    char current_char, previous_char;
    int capital_flag = 0, punctuation_flag = 0;

    // Parsing files
    fp_in = fopen(FIN, "r");
    fp_out = fopen(FOUT, "w");

    if (fp_in == NULL){
        printf("Error opening the file.");
        return 1;
    }
    if (fp_out == NULL){
        printf("Error opening the file.");
        return 2;
    }

    previous_char = fgetc(fp_in);
    do{
        while(count < 25 && current_char != EOF){
            current_char = fgetc(fp_in);
            if (previous_char == '\n'){
                previous_char = current_char;
                break;
            }
            if (isdigit(current_char)){
                current_char = '*';
            }
            if (previous_char == '.' || previous_char == '!' || previous_char == '?'){
                capital_flag = 1;
            }
            if (ispunct(previous_char)){
                if (current_char == ' ' || current_char == '\n' || ispunct(current_char)){
                    punctuation_flag = 0;
                }else{
                    punctuation_flag = 1;
                    count++;
                }
            }
            if (capital_flag && isalpha(current_char)) {
                if (count == 0) {
                    previous_char = toupper(previous_char);
                    capital_flag = 0;
                } else {
                    current_char = toupper(current_char);
                    capital_flag = 0;
                }
            }
            if (punctuation_flag) {
                fprintf(fp_out,"%c ", previous_char);
            }else{
                fprintf(fp_out,"%c", previous_char);
            }

            punctuation_flag = 0;
            previous_char = current_char;
            count++;
        }
        spaces = 25 - count;
        while (spaces > 0) {
            fprintf(fp_out," ");
            spaces--;
        }
        fprintf(fp_out,"| c:%d \n", count);
        count = 0;
    }while (current_char != EOF);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
