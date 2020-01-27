#include <assert.h>
#include <stdio.h>

#include "doubly_linked_list.h"
#include "singly_linked_list.h"

void singly_linked_list_tests(void)
{
    // create new list
    struct singly_linked_list *list = singly_linked_list_new();
    assert(list);

    // insert at beginning
    int item_1 = 1;
    struct singly_linked_list_node *node_1 = singly_linked_list_append(list, &item_1);
    assert(node_1);
    assert(node_1->data == &item_1);
    assert(*(int *)node_1->data == item_1);

    int item_2 = 2;
    struct singly_linked_list_node *node_2 = singly_linked_list_append(list, &item_2);
    assert(node_2);
    assert(node_2->data == &item_2);
    assert(*(int *)node_2->data == item_2);

    int item_4 = 4;
    struct singly_linked_list_node *node_4 = singly_linked_list_append(list, &item_4);
    assert(node_4);
    assert(node_4->data == &item_4);
    assert(*(int *)node_4->data == item_4);

    int item_5 = 5;
    struct singly_linked_list_node *node_5 = singly_linked_list_append(list, &item_5);
    assert(node_5);
    assert(node_5->data == &item_5);
    assert(*(int *)node_5->data == item_5);

    int item_6 = 6;
    struct singly_linked_list_node *node_6 = singly_linked_list_append(list, &item_6);
    assert(node_6);
    assert(node_6->data == &item_6);
    assert(*(int *)node_6->data == item_6);

    // insert after element
    int item_3 = 3;
    struct singly_linked_list_node *node_3 = singly_linked_list_insert_after(node_2, &item_3);
    assert(node_3);
    assert(node_3->data == &item_3);
    assert(*(int *)node_3->data == item_3);

    // insert at end
    int item_0 = 0;
    struct singly_linked_list_node *node_0 = singly_linked_list_prepend(list, &item_0);
    assert(node_0);
    assert(node_0->data == &item_0);
    assert(*(int *)node_0->data == item_0);

    // remove element
    singly_linked_list_remove(list, &item_0);
    singly_linked_list_remove(list, &item_4);

    // remove at index
    singly_linked_list_remove_at(list, 0);
    singly_linked_list_remove_at(list, 1);

    // count elements
    int count = singly_linked_list_count(list);
    assert(count == 3);

    // contains element
    bool contains_5 = singly_linked_list_contains(list, &item_5);
    assert(contains_5);

    // get elements
    int *item_p = singly_linked_list_get_at(list, 0);
    assert(item_p);
    assert(item_p == &item_2);
    assert(*item_p == item_2);
    item_p = singly_linked_list_get_at(list, 1);
    assert(item_p);
    assert(item_p == &item_5);
    assert(*item_p == item_5);
    item_p = singly_linked_list_get_at(list, 2);
    assert(item_p);
    assert(item_p == &item_6);
    assert(*item_p == item_6);

    // reverse
    singly_linked_list_reverse(list);

    // verify reverse
    item_p = singly_linked_list_get_at(list, 0);
    assert(item_p);
    assert(item_p == &item_6);
    assert(*item_p == item_6);
    item_p = singly_linked_list_get_at(list, 1);
    assert(item_p);
    assert(item_p == &item_5);
    assert(*item_p == item_5);
    item_p = singly_linked_list_get_at(list, 2);
    assert(item_p);
    assert(item_p == &item_2);
    assert(*item_p == item_2);

    singly_linked_list_delete(list);
}

void doubly_linked_list_tests(void)
{
    // create new list
    struct doubly_linked_list *list = doubly_linked_list_new();
    assert(list);

    // insert at beginning
    int item_1 = 1;
    struct doubly_linked_list_node *node_1 = doubly_linked_list_append(list, &item_1);
    assert(node_1);
    assert(node_1->data == &item_1);
    assert(*(int *)node_1->data == item_1);

    int item_2 = 2;
    struct doubly_linked_list_node *node_2 = doubly_linked_list_append(list, &item_2);
    assert(node_2);
    assert(node_2->data == &item_2);
    assert(*(int *)node_2->data == item_2);

    int item_4 = 4;
    struct doubly_linked_list_node *node_4 = doubly_linked_list_append(list, &item_4);
    assert(node_4);
    assert(node_4->data == &item_4);
    assert(*(int *)node_4->data == item_4);

    int item_5 = 5;
    struct doubly_linked_list_node *node_5 = doubly_linked_list_append(list, &item_5);
    assert(node_5);
    assert(node_5->data == &item_5);
    assert(*(int *)node_5->data == item_5);

    int item_6 = 6;
    struct doubly_linked_list_node *node_6 = doubly_linked_list_append(list, &item_6);
    assert(node_6);
    assert(node_6->data == &item_6);
    assert(*(int *)node_6->data == item_6);

    // insert after element
    int item_3 = 3;
    struct doubly_linked_list_node *node_3 = doubly_linked_list_insert_after(node_2, &item_3);
    assert(node_3);
    assert(node_3->data == &item_3);
    assert(*(int *)node_3->data == item_3);

    // insert at end
    int item_0 = 0;
    struct doubly_linked_list_node *node_0 = doubly_linked_list_prepend(list, &item_0);
    assert(node_0);
    assert(node_0->data == &item_0);
    assert(*(int *)node_0->data == item_0);

    doubly_linked_list_delete(list);
}

int main(int argc, char *argv[])
{
    singly_linked_list_tests();
    doubly_linked_list_tests();

    return 0;
}
