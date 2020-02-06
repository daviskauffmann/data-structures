#include "list.h"

#include <assert.h>
#include <malloc.h>
#include <stddef.h>

struct list *list_new(void)
{
    struct list *list = malloc(sizeof(struct list));
    assert(list);
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void list_delete(struct list *list)
{
    struct list_node *current = list->head;
    while (current)
    {
        struct list_node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

struct list_node *list_prepend(struct list *list, void *data)
{
    struct list_node *node = malloc(sizeof(struct list_node));
    assert(node);
    node->data = data;
    node->next = list->head;
    node->previous = NULL;
    if (list->head)
    {
        list->head->previous = node;
    }
    else
    {
        list->tail = node;
    }
    list->head = node;
    return node;
}

struct list_node *list_insert_after(struct list *list, struct list_node *previous, void *data)
{
    assert(previous);
    struct list_node *node = malloc(sizeof(struct list_node));
    assert(node);
    node->data = data;
    node->next = previous->next;
    previous->next = node;
    node->previous = previous;
    if (node->next)
    {
        node->next->previous = node;
    }
    if (previous == list->tail)
    {
        list->tail = node;
    }
    return node;
}

struct list_node *list_append(struct list *list, void *data)
{
    struct list_node *node = malloc(sizeof(struct list_node));
    assert(node);
    node->data = data;
    node->next = NULL;
    if (list->head)
    {
        struct list_node *last = list->head;
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
    list->tail = node;
    return node;
}

void list_remove(struct list *list, struct list_node *node)
{
    if (!list->head || !node)
    {
        return;
    }
    if (list->head == node)
    {
        list->head = node->next;
    }
    if (list->tail == node)
    {
        list->tail = node->previous;
    }
    if (node->next)
    {
        node->next->previous = node->previous;
    }
    if (node->previous)
    {
        node->previous->next = node->next;
    }
    free(node);
}

int list_count(struct list *list)
{
    int count = 0;
    list_for_each(list, node)
    {
        count++;
    }
    return count;
}

bool list_contains(struct list *list, void *data)
{
    list_for_each(list, node)
    {
        if (node->data == data)
        {
            return true;
        }
    }
    return false;
}

void *list_get_at(struct list *list, int index)
{
    int current_index = 0;
    list_for_each(list, node)
    {
        if (current_index == index)
        {
            return node->data;
        }
        current_index++;
    }
    return NULL;
}

void list_reverse(struct list *list)
{
    struct list_node *head = list->head;
    struct list_node *temp = NULL;
    struct list_node *current = list->head;
    while (current)
    {
        temp = current->previous;
        current->previous = current->next;
        current->next = temp;
        current = current->previous;
    }
    if (temp != NULL)
    {
        list->head = temp->previous;
    }
    list->tail = head;
}
