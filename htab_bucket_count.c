// Riesenie IJC-DU2, priklad b), 26.4.2021
// Autor: Richard Gajdosik, FIT
// Prelozene: gcc 9.3
#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"
size_t htab_bucket_count(const htab_t * t) {
    if(t != NULL){
        return  t->arr_size;
    }
    return 0;
}
