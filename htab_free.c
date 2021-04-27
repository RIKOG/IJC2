// Riesenie IJC-DU2, priklad b), 26.4.2021
// Autor: Richard Gajdosik, FIT
// Prelozene: gcc 9.3
#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"
void htab_free(htab_t * t){
    if(t != NULL){
        htab_clear(t);
        free(t);
    }
}