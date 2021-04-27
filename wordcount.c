// Riesenie IJC-DU2, priklad b), 26.4.2021
// Autor: Richard Gajdosik, FIT
// Prelozene: gcc 9.3
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "htab.h"
#include "htab_private.h"
#include "io.h"


/*  Pouzil som prvocislo 50021 pretoze spodna hranica novely je 40000 - 80000 slov 
    a je to vynikajuci kompromis medzi predpokladanou dlzkou inputu a vyhybaniu sa kolizii */
#define ARRAY_SIZE 50021
/*  1.2x vacsie nez 50021 z toho dovodu ze pre najefektivnejsie vyhybanie sa kolizii je potreba 
    mat hash table 1.2x vacsi nez ocakavany input */
#define NEW_ARRAY_SIZE 60029
#define WORD_LIMIT 128

void print_pair(htab_pair_t *pair){
    // Special case when we deleted the word, but not yet freed the table
    if(pair->key != NULL && pair->value != -1){
        printf("%s - ", pair->key);
    }
}

int main() {
    int  MAX_CHARS = WORD_LIMIT, n_of_chars = 0;
    char string[WORD_LIMIT] = {0}, key[] = "";
    FILE *fp = stdin;
    htab_t *table = htab_init(ARRAY_SIZE);
    if (table == NULL){
        return 1;
    }
    // read_word returns with each iteration a new word from file/stdin
    while((n_of_chars = read_word(string, MAX_CHARS, fp)) != EOF){
        htab_pair_t * test_pointer = htab_lookup_add(table, string);
        // If we encountered an error we end the program and free allocated space
        if(test_pointer == NULL){
            htab_free(table);
            fprintf(stderr, "Malloc has failed!\n");
            return 1;
        }
        test_pointer->value++;
        table->size++;
    }
#ifdef TEST
    htab_t *new = htab_move(NEW_ARRAY_SIZE, table);
    if(new == NULL){
        htab_free(table);
        fprintf(stderr, "Creating new hash table has failed!\n");
        return 1;
    }
    htab_free(table);
    table = new;
#endif
    htab_for_each(table, print_pair);

    size_t s = htab_size(table);
    size_t n = htab_bucket_count(table);

    printf("\nNumber of elements in table: %zu bucket size of table: %zu\n", s, n);

    bool deleted = htab_erase(table, key);
    printf("%d\n", deleted);


    htab_for_each(table, print_pair);

    s = htab_size(table);
    printf("Number of elements in table: %zu bucket size of table: %zu\n", s, n);


    htab_free(table);
    return 0;
}
