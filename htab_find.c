// Riesenie IJC-DU2, priklad b), 26.4.2021
// Autor: Richard Gajdosik, FIT
// Prelozene: gcc 9.3
#include <stdlib.h>
#include <stdio.h>
#include "htab.h"
#include "htab_private.h"

htab_pair_t *htab_find(htab_t *t, htab_key_t key) {
    if (t != NULL) {
        size_t i = 0;
        for (i = 0; i < t->arr_size; i++) {
            if (t->array[i] != NULL) {
                struct htab_item *ptr = t->array[i];
                while (ptr != NULL) {
                    if ((strcmp(ptr->htab_pair->key, key)) == 0) {
                        return ptr->htab_pair;
                    }
                    ptr = ptr->next;
                }
            }
        }
    }
    return NULL;
}