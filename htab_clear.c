// Riesenie IJC-DU2, priklad b), 26.4.2021
// Autor: Richard Gajdosik, FIT
// Prelozene: gcc 9.3
#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"

void htab_clear(htab_t *t) {
    if (t != NULL) {
        struct htab_item *ptr;
        for (size_t i = 0; i < t->arr_size; i++) {
            while (t->array[i] != NULL) {
                ptr = t->array[i]->next;
                free((char *) t->array[i]->htab_pair->key);
                free(t->array[i]->htab_pair);
                free(t->array[i]);
                t->array[i] = ptr;
            }
        }
    }
}