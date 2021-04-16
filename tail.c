#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.c"
typedef struct riadok {
    int pocet_riadkov;
    char *stlpec;
    struct riadok *p_dalsi_riadok;
} RIADOK;
char c;
int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        warning_msg("Nepodarilo sa otvorit subor", argv[1]);
        return -1;
    }
    while((c = getc(fp)) != EOF){
        printf("%c", c);

    }
    return 0;
}
