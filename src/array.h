#ifndef ARRAY_H
#define ARRAY_H

#include <malloc.h>
#include <stdint.h>

typedef struct array_header
{
    size_t len;
    size_t cap;
    char array[];
} array_header_t;

#define array__header(a) ((array_header_t *)(((char *)(a)) - offsetof(array_header_t, array)))
#define array__fits(a, n) (array_len(a) + (n) <= array_cap(a))
#define array__fit(a, n) (array__fits((a), (n)) ? 0 : ((a) = array__grow((a), array_len(a) + (n), sizeof(*(a)))))

#define array_len(a) ((a) ? array__header(a)->len : 0)
#define array_cap(a) ((a) ? array__header(a)->cap : 0)
#define array_push(a, x) (array__fit((a), 1), (a)[array__header(a)->len++] = (x))
#define array_free(a) ((a) ? (free(array__header(a)), (a) = NULL) : 0)

void *array__grow(const void *array, size_t len, size_t elem_size);

#endif
