// Riesenie IJC-DU2, priklad b), 26.4.2021
// Autor: Richard Gajdosik, FIT
// Prelozene: gcc 9.3
#include <stdio.h>
#include <ctype.h>
#include "io.h"
int read_word(char *s, int max, FILE *fp){
    int c, i = 0;
    // Toss white characters
    while(isspace(c = getc(fp))){
        if(c == EOF){
            return EOF;
        }
    }
    while(!(isspace(c))){
        s[i++] = c;
        if(c == EOF){
            s[i] = '\0';
            return EOF;
        }
        if(i >= max - 1){
            s[i] = '\0';
            fprintf(stderr, "%s", "The word was too long and it was shortened to 127 chars!\n");

            // Toss rest of the line
            while(!isspace(c = getc(fp))){
                if(c == EOF){
                    return EOF;
                }
            }
            return i;
        }
        c = getc(fp);
    }
    s[i] = '\0';
    return i;
}
