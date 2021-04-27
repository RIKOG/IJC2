// Riesenie IJC-DU2, priklad b), 26.4.2021
// Autor: Richard Gajdosik, FIT
// Prelozene: gcc 9.3
#include <stdlib.h>
#include <stdio.h>
#include "htab.h"
#include "htab_private.h"
htab_t *htab_init(size_t n) {
    if (n <= 0) {
        fprintf(stderr, "The inputted size is smaller or equal to 0!\n");
        return NULL;
    }
    htab_t *ptr = malloc(sizeof(htab_t) + sizeof(struct htab_item *) * n);
    if (ptr == NULL) {
        fprintf(stderr, "Malloc has failed!\n");
        return NULL;
    }
    ptr->size = 0;
    ptr->arr_size = n;
    for (size_t i = 0; i < n; i++) {
        ptr->array[i] = NULL;
    }
    return ptr;
}