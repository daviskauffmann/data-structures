#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#define list_for_each(l, n) for (list_node_t *n = l->head; n; n = n->next)
#define list_for_each_rev(l, n) for (list_node_t *n = l->tail; n; n = n->previous)

typedef struct list
{
    struct list_node *head;
    struct list_node *tail;
} list_t;

typedef struct list_node
{
    void *data;
    struct list_node *next;
    struct list_node *prev;
} list_node_t;

list_t *list_new(void);
void list_delete(list_t *l);

list_node_t *list_prepend(list_t *l, void *data);
list_node_t *list_insert_after(list_t *l, list_node_t *prev, void *data);
list_node_t *list_append(list_t *l, void *data);

void list_remove(list_t *l, list_node_t *n);

int list_count(list_t *l);
bool list_contains(list_t *l, void *data);

void *list_get_at(list_t *l, int idx);

void list_reverse(list_t *l);

#endif
