// Riesenie IJC-DU2, priklad b), 26.4.2021
// Autor: Richard Gajdosik, FIT
// Prelozene: gcc 9.3
#include <stdlib.h>
#include <stdio.h>
#include "htab.h"
#include "htab_private.h"
htab_t *htab_move(size_t n, htab_t *from) {
    if(n == 0 || from == NULL){
        return NULL;
    }
    htab_t *new = htab_init(n);
    if (new == NULL) {
        fprintf(stderr, "Malloc has failed!\n");
        return NULL;
    }
    return NULL;
}