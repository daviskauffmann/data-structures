#include "doubly_linked_list.h"

#include <assert.h>
#include <malloc.h>
#include <stddef.h>

struct doubly_linked_list *doubly_linked_list_new(void)
{
    struct doubly_linked_list *list = malloc(sizeof(struct doubly_linked_list));
    assert(list);
    list->head = NULL;
    return list;
}

void doubly_linked_list_delete(struct doubly_linked_list *list)
{
    free(list);
}

struct doubly_linked_list_node *doubly_linked_list_prepend(struct doubly_linked_list *list, void *data)
{
    struct doubly_linked_list_node *node = malloc(sizeof(struct doubly_linked_list_node));
    assert(node);
    node->data = data;
    node->next = list->head;
    node->previous = NULL;
    if (list->head)
    {
        list->head->previous = node;
    }
    list->head = node;
    return node;
}

struct doubly_linked_list_node *doubly_linked_list_insert_after(struct doubly_linked_list_node *previous, void *data)
{
    assert(previous);
    struct doubly_linked_list_node *node = malloc(sizeof(struct doubly_linked_list_node));
    assert(node);
    node->data = data;
    node->next = previous->next;
    previous->next = node;
    node->previous = previous;
    if (node->next)
    {
        node->next->previous = node;
    }
    return node;
}

struct doubly_linked_list_node *doubly_linked_list_append(struct doubly_linked_list *list, void *data)
{
    struct doubly_linked_list_node *node = malloc(sizeof(struct doubly_linked_list_node));
    assert(node);
    node->data = data;
    node->next = NULL;
    if (list->head)
    {
        struct doubly_linked_list_node *last = list->head;
        while (last->next)
        {
            last = last->next;
        }
        last->next = node;
        node->previous = last;
    }
    else
    {
        node->previous = NULL;
        list->head = node;
    }
    return node;
}
