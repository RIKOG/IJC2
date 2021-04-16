#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.c"
//todo pridat kontrolu ci sa podaril malloc
typedef struct riadok {
    char riadok[545];
    struct riadok *p_dalsi_riadok;
} RIADOK;

int main(int argc, char *argv[]) {
    int c, i = 0, pocet_riadkov_argument = 10, pocet_riadkov_struct = 0;

    RIADOK *head = NULL;
    RIADOK *line_ptr = (RIADOK *) malloc(sizeof(RIADOK));
    // We want to be able to find the end of the struct chain thanks to the last pointer being NULL
    line_ptr->p_dalsi_riadok = NULL;

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        warning_msg("Nepodarilo sa otvorit subor", argv[1]);
        return -1;
    }

    while((c = getc(fp)) != EOF){
        if(c == '\n'){
            if(head == NULL){
                head = line_ptr;
            }
            // If we found the needed amount of lines, we just want to "move" them along the chain backwards
            if (pocet_riadkov_struct == pocet_riadkov_argument){
                //tu chcem odstranit prvy struct a pripojit dalsi na konci retaze
            }
            pocet_riadkov_struct++;
            // todo there will be a problem when the text file will end with \n and then right away with EOF, there is getc because we dont want \n written in our struct
            // todo write a limiter for the maximum amount of characters in one line
            line_ptr
            c = getc;
        }
        line_ptr->riadok[i++] = c;

//        printf("%c", c);

    }
    return 0;
}
