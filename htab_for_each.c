// Riesenie IJC-DU2, priklad b), 26.4.2021
// Autor: Richard Gajdosik, FIT
// Prelozene: gcc 9.3
#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"

void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *data)) {
    if (t != NULL && f != NULL) {
        struct htab_item *help_ptr_add = NULL;
        for (size_t i = 0; i < t->arr_size; i++) {
            if (t->array[i] != NULL) {
                help_ptr_add = t->array[i];
                while (help_ptr_add != NULL) {
                    f(help_ptr_add->htab_pair);
                    help_ptr_add = help_ptr_add->next;
                }
            }
        }
    }
}