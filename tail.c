#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.c"
//todo pridat kontrolu ci sa podaril malloc a otváranie súboru
//todo add +5 POSIX features
//todo free allocated space
typedef struct line {
    char line[512];
    struct line *p_next_line;
} LINE;

int main(int argc, char *argv[]) {
    int c, i = 0, n_of_lines_argument = 10, n_of_lines_struct = 0;

    LINE *head = NULL;
    LINE *line_ptr = (LINE *) malloc(sizeof(LINE));
    LINE *tmp_ptr = NULL;
    // We want to be able to find the end of the struct chain thanks to the last pointer being NULL
    line_ptr->p_next_line = NULL;

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        warning_msg("The file failed to open", argv[1]);
        return -1;
    }

    while((c = getc(fp)) != EOF){
        if(c == '\n' || i == 511){
            // Making sure lines arent longer than 512 characters with reserving one last index in an array for \0
            if(i == 511){
                // We toss the rest of the line
                while(c != '\n'){
                    // Solving a problem where the text file ends while tossing, we return EOF back so another if statement can catch it and end the main while loop
                    if(c == EOF){
                        ungetc(c, fp);
                        break;
                    }
                    c = getc(fp);
                }
            }

            line_ptr->line[i] = '\0';
            if(head == NULL){
                head = line_ptr;
            }
            c = getc(fp);
            // Solving a problem where the text file doesnt end with \nEOF but just with EOF
            if(c == EOF){
                ungetc(c, fp);
                break;
            }
            // If we found the needed amount of lines, we just want to "move" them along the chain backwards
            if (n_of_lines_struct >= n_of_lines_argument - 1){
                tmp_ptr = head->p_next_line;
                free(head);
                head = tmp_ptr;
            }
            n_of_lines_struct++;
            tmp_ptr = line_ptr;
            line_ptr = (LINE *) malloc(sizeof(LINE));
            line_ptr->p_next_line = NULL;
            // We connect our newly created struct to the last one
            tmp_ptr->p_next_line = line_ptr;
            i = 0;
        }
        line_ptr->line[i++] = c;
    }
    // If last line in text file ends just with EOF if statement doesnt get triggered, we need to set line[i] to \0
    line_ptr->line[i] = '\0';
    tmp_ptr = head;
    while(tmp_ptr != NULL){
        printf("%s\n", tmp_ptr->line);
        tmp_ptr = tmp_ptr->p_next_line;
    }
    return 0;
}
