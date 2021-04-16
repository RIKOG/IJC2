#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.c"
//todo pridat kontrolu ci sa podaril malloc
typedef struct line {
    char line[545];
    struct line *p_next_line;
} LINE;

int main(int argc, char *argv[]) {
    int c, i = 0, n_of_lines_argument = 10, n_of_lines_struct = 0;

    LINE *head = NULL;
    LINE *line_ptr = (LINE *) malloc(sizeof(LINE));
    // We want to be able to find the end of the struct chain thanks to the last pointer being NULL
    line_ptr->p_next_line = NULL;

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        warning_msg("The file failed to open", argv[1]);
        return -1;
    }

    while((c = getc(fp)) != EOF){
        if(c == '\n'){
            if(head == NULL){
                head = line_ptr;
            }
            // If we found the needed amount of lines, we just want to "move" them along the chain backwards
            if (n_of_lines_struct == n_of_lines_argument){
                //tu chcem odstranit prvy struct a pripojit dalsi na konci retaze
            }
            n_of_lines_struct++;
            // todo there will be a problem when the text file will end with \n and then right away with EOF, there is getc because we dont want \n written in our struct
            // todo write a limiter for the maximum amount of characters in one line
            line_ptr
            c = getc;
        }
        line_ptr->line[i++] = c;

//        printf("%c", c);

    }
    return 0;
}
