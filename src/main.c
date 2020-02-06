#include <assert.h>
#include <stdio.h>

#include "list.h"

void list_test(void)
{
    // create new list
    struct list *list = list_new();
    assert(list);

    // insert at beginning
    int item_1 = 1;
    struct list_node *node_1 = list_append(list, &item_1);
    assert(node_1);
    assert(node_1->data == &item_1);
    assert(*(int *)node_1->data == item_1);

    int item_2 = 2;
    struct list_node *node_2 = list_append(list, &item_2);
    assert(node_2);
    assert(node_2->data == &item_2);
    assert(*(int *)node_2->data == item_2);

    int item_4 = 4;
    struct list_node *node_4 = list_append(list, &item_4);
    assert(node_4);
    assert(node_4->data == &item_4);
    assert(*(int *)node_4->data == item_4);

    int item_5 = 5;
    struct list_node *node_5 = list_append(list, &item_5);
    assert(node_5);
    assert(node_5->data == &item_5);
    assert(*(int *)node_5->data == item_5);

    int item_6 = 6;
    struct list_node *node_6 = list_append(list, &item_6);
    assert(node_6);
    assert(node_6->data == &item_6);
    assert(*(int *)node_6->data == item_6);

    // insert after element
    int item_3 = 3;
    struct list_node *node_3 = list_insert_after(list, node_2, &item_3);
    assert(node_3);
    assert(node_3->data == &item_3);
    assert(*(int *)node_3->data == item_3);

    // insert at end
    int item_0 = 0;
    struct list_node *node_0 = list_prepend(list, &item_0);
    assert(node_0);
    assert(node_0->data == &item_0);
    assert(*(int *)node_0->data == item_0);

    // remove element
    list_remove(list, node_0);
    list_remove(list, node_4);
    list_remove(list, node_6);

    // count elementss
    int count = list_count(list);
    assert(count == 4);

    // contains element
    bool contains_5 = list_contains(list, &item_5);
    assert(contains_5);

    // get elements
    int *item_p;
    item_p = list_get_at(list, 0);
    assert(item_p);
    assert(item_p == &item_1);
    assert(*item_p == item_1);
    item_p = list_get_at(list, 1);
    assert(item_p);
    assert(item_p == &item_2);
    assert(*item_p == item_2);
    item_p = list_get_at(list, 2);
    assert(item_p);
    assert(item_p == &item_3);
    assert(*item_p == item_3);
    item_p = list_get_at(list, 3);
    assert(item_p);
    assert(item_p == &item_5);
    assert(*item_p == item_5);

    // reverse
    list_reverse(list);

    // verify reverse
    item_p = list_get_at(list, 0);
    assert(item_p);
    assert(item_p == &item_5);
    assert(*item_p == item_5);
    item_p = list_get_at(list, 1);
    assert(item_p);
    assert(item_p == &item_3);
    assert(*item_p == item_3);
    item_p = list_get_at(list, 2);
    assert(item_p);
    assert(item_p == &item_2);
    assert(*item_p == item_2);
    item_p = list_get_at(list, 3);
    assert(item_p);
    assert(item_p == &item_1);
    assert(*item_p == item_1);

    list_delete(list);
}

int main(int argc, char *argv[])
{
    list_test();

    return 0;
}
