#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "stdbool.h"

#define singly_linked_list_for_each(list, node) for (struct singly_linked_list_node *node = list->head; node != NULL; node = node->next)

struct singly_linked_list_node
{
    void *data;
    struct singly_linked_list_node *next;
};

struct singly_linked_list
{
    struct singly_linked_list_node *head;
};

struct singly_linked_list *singly_linked_list_new(void);
void singly_linked_list_delete(struct singly_linked_list *list);

struct singly_linked_list_node *singly_linked_list_prepend(struct singly_linked_list *list, void *data);
struct singly_linked_list_node *singly_linked_list_insert_after(struct singly_linked_list_node *previous, void *data);
struct singly_linked_list_node *singly_linked_list_append(struct singly_linked_list *list, void *data);

void singly_linked_list_remove(struct singly_linked_list *list, void *data);
void singly_linked_list_remove_at(struct singly_linked_list *list, int index);

int singly_linked_list_count(struct singly_linked_list *list);
bool singly_linked_list_contains(struct singly_linked_list *list, void *data);

void *singly_linked_list_get_at(struct singly_linked_list *list, int index);

void singly_linked_list_reverse(struct singly_linked_list *list);

#endif
