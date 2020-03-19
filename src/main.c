#include <assert.h>
#include <stdio.h>

#include "array.h"
#include "list.h"

void array_test(void)
{
    int *a = NULL;
    assert(array_len(a) == 0);
    const size_t n = 1024;
    for (size_t i = 0; i < n; i++)
    {
        array_push(a, i);
    }
    assert(array_len(a) == n);
    for (size_t i = 0; i < array_len(a); i++)
    {
        assert(a[i] == (int)i);
    }
    array_free(a);
    assert(a == NULL);
    assert(array_len(a) == 0);
}

void list_test(void)
{
    // create new list
    list_t *l = list_new();
    assert(l);

    // insert at beginning
    int i1 = 1;
    list_node_t *n1 = list_append(l, &i1);
    assert(n1);
    assert(n1->data == &i1);
    assert(*(int *)n1->data == i1);

    int i2 = 2;
    list_node_t *n2 = list_append(l, &i2);
    assert(n2);
    assert(n2->data == &i2);
    assert(*(int *)n2->data == i2);

    int i4 = 4;
    list_node_t *n4 = list_append(l, &i4);
    assert(n4);
    assert(n4->data == &i4);
    assert(*(int *)n4->data == i4);

    int i5 = 5;
    list_node_t *n5 = list_append(l, &i5);
    assert(n5);
    assert(n5->data == &i5);
    assert(*(int *)n5->data == i5);

    int i6 = 6;
    list_node_t *n6 = list_append(l, &i6);
    assert(n6);
    assert(n6->data == &i6);
    assert(*(int *)n6->data == i6);

    // insert after element
    int i3 = 3;
    list_node_t *n3 = list_insert_after(l, n2, &i3);
    assert(n3);
    assert(n3->data == &i3);
    assert(*(int *)n3->data == i3);

    // insert at end
    int i0 = 0;
    list_node_t *n0 = list_prepend(l, &i0);
    assert(n0);
    assert(n0->data == &i0);
    assert(*(int *)n0->data == i0);

    // remove element
    list_remove(l, n0);
    list_remove(l, n4);
    list_remove(l, n6);

    // count elementss
    assert(list_count(l) == 4);

    // contains element
    assert(list_contains(l, &i5));

    // get elements
    int *ip;
    ip = list_get(l, 0);
    assert(ip);
    assert(ip == &i1);
    assert(*ip == i1);
    ip = list_get(l, 1);
    assert(ip);
    assert(ip == &i2);
    assert(*ip == i2);
    ip = list_get(l, 2);
    assert(ip);
    assert(ip == &i3);
    assert(*ip == i3);
    ip = list_get(l, 3);
    assert(ip);
    assert(ip == &i5);
    assert(*ip == i5);

    // reverse
    list_reverse(l);

    // verify reverse
    ip = list_get(l, 0);
    assert(ip);
    assert(ip == &i5);
    assert(*ip == i5);
    ip = list_get(l, 1);
    assert(ip);
    assert(ip == &i3);
    assert(*ip == i3);
    ip = list_get(l, 2);
    assert(ip);
    assert(ip == &i2);
    assert(*ip == i2);
    ip = list_get(l, 3);
    assert(ip);
    assert(ip == &i1);
    assert(*ip == i1);

    list_delete(l);
}

int main(int argc, char *argv[])
{
    array_test();
    list_test();

    return 0;
}
