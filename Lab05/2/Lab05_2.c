#include <stdio.h>
#include <string.h>
#define MAXL 200
#define MAX_S 30

typedef struct dict{
    char original[7];
    char replace[7];
}dict;

void converter(dict t[], int s, char line[]);

void converter(dict t[] ,int s, char line[]){
    int i, j, k;
    int len_line = strlen(line);
    int len_w; // length of the keyword we are going to look for
    int len_rep; // length of the replacement string
    char tmp[len_line];

    for (i =0; i < s; ++i){
        len_w = strlen(t[i].original);
        len_rep = strlen(t[i].replace);
        /* searching in the line */
        for (j = 0; j <= len_line - len_w; ++j){
            k = 0;
            while (k < len_w && line[j+k] == t[i].original[k]){
                k++;
            }
            if (k == len_w){
                strcpy(tmp, line+j+len_w);
                strcpy(line+j,t[i].replace);
                strcpy(line+j+len_rep, tmp);
                j += len_rep -1;
            }
        }
    }
}


int main() {
    FILE *fpin, *fpout, *fpdict;
    dict table[MAX_S];
    char line[MAXL];
    int s, i = 0;

    /* Parsing the files */
    fpin = fopen("../source.txt", "r");
    fpout = fopen("../output.txt", "w");
    fpdict = fopen("../dictionary.txt", "r");

    if (fpin == NULL || fpdict == NULL || fpout == NULL){
        printf("Error opening files");
        return 1;
    }
    /* Reading the conversion table */
    fscanf(fpdict, "%d", &s);
    if ( s > MAX_S){
        printf("S is higher than the threshold");
        return 1;
    }

    while ((fscanf(fpdict, "%s %s", table[i].replace, table[i].original)) == 2){
        ++i;
    }
    fclose(fpdict);

    printf("._ _ _ _ _ _ _ _ .\n");
    for (i = 0; i < s; ++i) {
        printf("| %-6s | %-6s|\n", table[i].replace, table[i].original);
    }
    printf("'- - - - - - - - '\n");
    /* Re-encoding of the text based on the conversion table */
    do{
        fgets(line,MAXL, fpin);
        converter(table, s, line);
        fprintf(fpout, "%s", line);

    }while(!feof(fpin));

    fclose(fpin);
    fclose(fpout);

    return 0;
}
