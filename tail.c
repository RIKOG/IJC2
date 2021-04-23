#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Riesenie IJC-DU2, priklad a), 18.4.2021
// Autor: Richard Gajdosik, FIT
// Prelozene: gcc 9.3
//todo pridat kontrolu ci sa podaril malloc a otváranie súboru
//todo add +5 POSIX features
//todo free allocated space
//todo more arguments
//todo test with zero

typedef struct line {
    char line[512];
    struct line *p_next_line;
} LINE;

void free_struct(LINE *head){
    LINE *tmp_ptr = head->p_next_line;
    while(head != NULL){
        free(head);
        head = tmp_ptr;
        if(head != NULL){
            tmp_ptr = tmp_ptr->p_next_line;
        }
    }
}

int main(int argc, char *argv[]) {
    int c, i = 0, n_of_lines_argument_int = 10, n_of_lines_struct = 0;
    char n_of_lines_argument_char[10000] = {0};
    if(argc > 4){
        fprintf(stderr, "%s", "Too much arguments!\n");
    }
    // When one of the arguments is a name of the file
    if(argc == 2 || argc == 4){
        // When the arguments contain name of the file and posix tail arguments
        if(argc == 4){
            // If the posix argument is correct
            if(strcmp(argv[1], "-n") == 0){
                // We copy the content of the next argument to check if we count the number of lines from the start or end
                strcpy(n_of_lines_argument_char, argv[2]);
                // We have to count the lines from start in the main loop
                if(n_of_lines_argument_char[0] == '+'){
                    // todo rethink the logic of the main loop
                    printf("test\n");
                }
                // Conversion from char array to int
                n_of_lines_argument_int = atoi(n_of_lines_argument_char);
                // If argument contains zero or non numeric characters, atoi returns numbers encountered until that point or zero
                if(n_of_lines_argument_int == 0){
                    fprintf(stderr, "%s", "argument after -n didnt contain any numbers or you put in 0!\n");
                    exit(1);
                }
                // Getting absolute value of argument if the number was written with "-" infront of it
                if(n_of_lines_argument_int < 0){
                    n_of_lines_argument_int *= -1;
                }
//                printf("%d\n", n_of_lines_argument_int);
            } else {
                fprintf(stderr, "%s", "Wrong argument, expected \"-n\" !\n");
                exit(1);
            }
        }
        LINE *head = NULL;
        LINE *line_ptr = (LINE *) malloc(sizeof(LINE));
        LINE *tmp_ptr = NULL;
        // We want to be able to find the end of the struct chain thanks to the last pointer being NULL
        line_ptr->p_next_line = NULL;

        FILE *fp = fopen(argv[argc-1], "r");

        if(fp == NULL){
            fprintf(stderr, "%s", "The file failed to open!\n");
        }
//        fp = stdin;
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
                if (n_of_lines_struct >= n_of_lines_argument_int - 1){
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
        free_struct(head);
    }
    return 0;
}
