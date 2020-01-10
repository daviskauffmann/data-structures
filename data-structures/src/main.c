#include <stdio.h>

#include "singly_linked_list.h"

int main(int argc, char *argv[])
{
    struct singly_linked_list *list = singly_linked_list_new();
    printf("new\n");
    singly_linked_list_for_each(list, node)
    {
        printf("%d\n", *(int *)node->data);
    }
    printf("\n");

    int item1 = 1;
    struct singly_linked_list_node *node1 = singly_linked_list_append(list, &item1);
    int item2 = 2;
    struct singly_linked_list_node *node2 = singly_linked_list_append(list, &item2);
    int item4 = 4;
    struct singly_linked_list_node *node4 = singly_linked_list_append(list, &item4);
    int item5 = 5;
    struct singly_linked_list_node *node5 = singly_linked_list_append(list, &item5);
    int item6 = 6;
    struct singly_linked_list_node *node6 = singly_linked_list_append(list, &item6);
    printf("append 1, 2, 4, 5, 6\n");
    singly_linked_list_for_each(list, node)
    {
        printf("%d\n", *(int *)node->data);
    }
    printf("\n");

    int item3 = 3;
    struct singly_linked_list_node *node3 = singly_linked_list_insert_after(node2, &item3);
    printf("insert 3 after 2\n");
    singly_linked_list_for_each(list, node)
    {
        printf("%d\n", *(int *)node->data);
    }
    printf("\n");

    int item0 = 0;
    struct singly_linked_list_node *node0 = singly_linked_list_prepend(list, &item0);
    printf("prepend 0\n");
    singly_linked_list_for_each(list, node)
    {
        printf("%d\n", *(int *)node->data);
    }
    printf("\n");

    singly_linked_list_remove(list, &item0);
    printf("remove 0\n");
    singly_linked_list_for_each(list, node)
    {
        printf("%d\n", *(int *)node->data);
    }
    printf("\n");

    singly_linked_list_remove(list, &item4);
    printf("remove 4\n");
    singly_linked_list_for_each(list, node)
    {
        printf("%d\n", *(int *)node->data);
    }
    printf("\n");

    singly_linked_list_remove_at(list, 0);
    printf("remove first\n");
    singly_linked_list_for_each(list, node)
    {
        printf("%d\n", *(int *)node->data);
    }
    printf("\n");

    singly_linked_list_remove_at(list, 1);
    printf("remove second\n");
    singly_linked_list_for_each(list, node)
    {
        printf("%d\n", *(int *)node->data);
    }
    printf("\n");

    int count = singly_linked_list_count(list);
    printf("count = %d\n", count);
    printf("\n");

    bool contains_5 = singly_linked_list_contains(list, &item5);
    printf("contains 5 = %s\n", contains_5 ? "true" : "false");
    printf("\n");

    int *third_item = singly_linked_list_get_at(list, 2);
    printf("third item = %d\n", *third_item);
    printf("\n");

    singly_linked_list_delete(list);
    printf("delete\n");

    return 0;
}
