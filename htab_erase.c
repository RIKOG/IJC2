// Riesenie IJC-DU2, priklad b), 26.4.2021
// Autor: Richard Gajdosik, FIT
// Prelozene: gcc 9.3
#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"

bool htab_erase(htab_t *t, htab_key_t key) {
    if (t != NULL) {
        htab_pair_t *help_ptr_find = htab_find(t, key);
        if (help_ptr_find != NULL) {
            t->size -= help_ptr_find->value;
            help_ptr_find->value = -1;
        }
//        int i = 0;
//        for (i = 0; i < t->arr_size; i++) {
//            struct htab_item *ptr = t->array[i];
//            struct htab_item *ptr_2 = t->array[i];
//
//            while(ptr != NULL){
//                // If we found our key
//                if ((strcmp(ptr->htab_pair->key, key)) == 0) {
//                    free((char*)ptr->htab_pair->key);
//                    // We go over deleted struct
//                    ptr_2->next = ptr->next;
//                    t->size -= ptr->htab_pair->value;
//                    free(ptr);
//                    return 1;
//                }
//                ptr_2 = ptr;
//                ptr = ptr->next;
//            }
//        }
    }
    return 0;
}