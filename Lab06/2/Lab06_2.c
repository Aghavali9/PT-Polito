#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SEQ 20
#define MAX_SEQ_LEN 5
#define MAX_WORD_LEN 25
#define MAX_LINE_LEN 200

void str_Lower(char s[]);
int line_counter(FILE *ptr);
void lookup(char words[200][MAX_WORD_LEN], char seq[][MAX_SEQ_LEN], int n, int l);
int line_to_word(char lines[][MAX_LINE_LEN],char words[200][MAX_WORD_LEN], int l);

void str_Lower(char s[]){
    int i, l = strlen(s);
    for (i=0; i<l; i++)
        s[i]=tolower(s[i]);
}

int line_counter(FILE *ptr){ 
    int num = 0;
    char line[MAX_LINE_LEN]; // I don't care about this
    while (fgets(line, MAX_LINE_LEN, ptr) != NULL){
        num++;
    }
    return num;
}

void lookup(char words[][MAX_WORD_LEN], char seq[][MAX_SEQ_LEN], int num_words, int n) {
    int len_seq;
    char tmp[200][MAX_WORD_LEN];
    for (int i = 0; i < num_words; i++){
        strcpy(tmp[i],words[i]);
        str_Lower(tmp[i]);
    }
    for (int i = 0; i < n; ++i) {
        printf("Sequence %s is contained in:\n\n", seq[i]);
        len_seq = strlen(seq[i]);
        char tmp_seq[len_seq];
        strcpy(tmp_seq, seq[i]);
        str_Lower(tmp_seq);

        for (int j = 0; j < num_words; j++) {
            if (strstr(tmp[j], tmp_seq) != NULL) {
                printf("%-12s (position %2d)\n", words[j], j+1);
            }
        }

        }

}

int line_to_word(char lines[][MAX_LINE_LEN],char words[200][MAX_WORD_LEN],int l) {
    int word_count = 0; // count of words found so far

    for (int i = 0; i < l; ++i){
        int len = strlen(lines[i]);
        int word_start = 0; // index of the start of the current word
        for (int j = 0; j < len; j++) {
            // check if the current character is a space or punctuation
            if (isspace(lines[i][j]) || ispunct(lines[i][j])) {
                // copy the current word to the array
                int word_len = j - word_start;
                if (word_len > 0) {
                    strncpy(words[word_count], lines[i] + word_start, word_len);
                    /* Adding a null terminator at the end of the current word in the words array.
                     * This is necessary to indicate the end of the string.*/
                    words[word_count][word_len] = '\0';
                    word_count++;
                }
                word_start = j + 1; // set the start of the next word
            }
        }

        // copy the last word (if any)
        if (word_start < len) {
            int word_len = len - word_start;
            strncpy(words[word_count], lines[i] + word_start, word_len);
            words[word_count][word_len] = '\0';
            word_count++;
        }

    }
    return word_count;
}


int main() {
    FILE *fpseq, *fpin;
    int n,l;
    char seq[MAX_SEQ][MAX_SEQ_LEN];
    char words[200][MAX_WORD_LEN]; //TODO: ask how many this word number should be
    /* Parsing the files */
    fpin = fopen("../text.txt", "r");
    fpseq = fopen("../sequences.txt", "r");
    if  (fpin == NULL || fpseq == NULL){
        printf("Error opening files");
        return 1;
    }
    fscanf(fpseq,"%d", &n); // reading the number of sequences

    for (int i = 0; i < n; ++i){
        fscanf(fpseq, "%s", seq[i]);
    }
    fclose(fpseq);
    l = line_counter(fpin);
    char lines[l][MAX_LINE_LEN];
    rewind(fpin);
    for (int i = 0; i < l; ++i){
        fgets(lines[i],MAX_LINE_LEN,fpin);
    }
    fclose(fpin);
    

   int num_words  = line_to_word(lines,words,l);
    lookup(words,seq,num_words,n);

    return 0;
}
