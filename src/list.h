#ifndef list_H
#define list_H

#include <stdbool.h>

#define list_for_each(list, node) for (struct list_node *node = list->head; node; node = node->next)
#define list_for_each_rev(list, node) for (struct list_node *node = list->tail; node; node = node->previous)

struct list_node
{
    void *data;
    struct list_node *next;
    struct list_node *previous;
};

struct list
{
    struct list_node *head;
    struct list_node *tail;
};

struct list *list_new(void);
void list_delete(struct list *list);

struct list_node *list_prepend(struct list *list, void *data);
struct list_node *list_insert_after(struct list *list, struct list_node *previous, void *data);
struct list_node *list_append(struct list *list, void *data);

void list_remove(struct list *list, struct list_node *node);

int list_count(struct list *list);
bool list_contains(struct list *list, void *data);

void *list_get_at(struct list *list, int index);

void list_reverse(struct list *list);

#endif
