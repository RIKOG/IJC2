// Riesenie IJC-DU2, priklad b), 26.4.2021
// Autor: Richard Gajdosik, FIT
// Prelozene: gcc 9.3
#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"



htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key) {
    if (t != NULL && key != NULL) {
        int index = (htab_hash_function(key) % t->arr_size);
        struct htab_item *help_ptr_add_2 = NULL;
        htab_pair_t *help_ptr_find = NULL;

        // Ak je na danom indexe nula slov zapisanych
        if (t->array[index] == NULL) {
            t->array[index] = malloc(sizeof(struct htab_item));
            t->array[index]->htab_pair = malloc(sizeof(htab_pair_t));
            // key je constant
            char *kluc = malloc(strlen(key));
            // If malloc fails
            if(t->array[index] == NULL || t->array[index]->htab_pair == NULL || kluc == NULL){
                return NULL;
            }
            strcpy(kluc, key);
            t->array[index]->htab_pair->key = kluc;
            t->array[index]->next = NULL;
            t->array[index]->htab_pair->value = 0;
            return t->array[index]->htab_pair;
        } else {
            // Skontrolujeme ci sa dane slovo nenachadza v tabulke
            help_ptr_find = htab_find(t, key);
            // Ak sa nachadza, zvysime jeho vyskyt
            if (help_ptr_find != NULL) {
                return t->array[index]->htab_pair;
            } else {
                help_ptr_add_2 = malloc(sizeof(htab_pair_t));
                help_ptr_add_2->htab_pair = t->array[index]->htab_pair;
                help_ptr_add_2->next = t->array[index]->next;
                t->array[index] = NULL;
                t->array[index] = malloc(sizeof(struct htab_item));
                t->array[index]->htab_pair = malloc(sizeof(htab_pair_t));
                char *kluc = malloc(strlen(key));
                if(t->array[index] == NULL || t->array[index]->htab_pair == NULL || kluc == NULL){
                    return NULL;
                }
                strcpy(kluc, key);
                t->array[index]->htab_pair->key = kluc;
                t->array[index]->next = help_ptr_add_2;
                t->array[index]->htab_pair->value = 0;
                return t->array[index]->htab_pair;
            }
        }
    }
    return NULL;
}