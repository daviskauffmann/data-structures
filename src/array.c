#include "array.h"

#include <assert.h>

#define MAX(x, y) ((x) >= (y) ? (x) : (y))

void *array__grow(const void *a, size_t len, size_t elem_size)
{
    size_t cap = MAX(1 + 2 * array_cap(a), len);
    assert(len <= cap);
    size_t size = offsetof(array_header_t, array) + cap * elem_size;
    array_header_t *h;
    if (a)
    {
        h = realloc(array__header(a), size);
    }
    else
    {
        h = malloc(size);
        h->len = 0;
    }
    h->cap = cap;
    return h->array;
}
