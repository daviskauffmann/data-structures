#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>

#define doubly_linked_list_for_each(list, node) for (struct doubly_linked_list_node *node = list->head; node != NULL; node = node->next)
// #define doubly_linked_list_for_each_rev(list, node) for (struct doubly_linked_list_node *node = list->head; node != NULL; node = node->next)

struct doubly_linked_list_node
{
    void *data;
    struct doubly_linked_list_node *next;
    struct doubly_linked_list_node *previous;
};

struct doubly_linked_list
{
    struct doubly_linked_list_node *head;
};

struct doubly_linked_list *doubly_linked_list_new(void);
void doubly_linked_list_delete(struct doubly_linked_list *list);

struct doubly_linked_list_node *doubly_linked_list_prepend(struct doubly_linked_list *list, void *data);
struct doubly_linked_list_node *doubly_linked_list_insert_after(struct doubly_linked_list_node *previous, void *data);
struct doubly_linked_list_node *doubly_linked_list_append(struct doubly_linked_list *list, void *data);

#endif
