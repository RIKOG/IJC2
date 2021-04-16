#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct riadok {
    int pocet_riadkov;
    char *stlpec;
    struct riadok *p_dalsi_riadok;
} RIADOK;

int main(int argc, char *argv[]) {

    printf("%d\n", argc);
    return 0;
}
