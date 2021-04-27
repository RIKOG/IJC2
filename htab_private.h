#ifndef __HTABLE_PRIVATE_H__
#define __HTABLE_PRIVATE_H__
#pragma once
#include "htab.h"
struct htab {
    size_t size;
    size_t arr_size;
    struct htab_item *array[];
};

struct htab_item {
    struct htab_pair *htab_pair;
    struct htab_item *next;
};

#endif