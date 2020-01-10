#include "singly_linked_list.h"

#include <assert.h>
#include <malloc.h>

struct singly_linked_list *singly_linked_list_new(void)
{
    struct singly_linked_list *list = malloc(sizeof(struct singly_linked_list));
    assert(list);
    list->head = NULL;
    return list;
}

void singly_linked_list_delete(struct singly_linked_list *list)
{
    struct singly_linked_list_node *current = list->head;
    while (current)
    {
        struct singly_linked_list_node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

struct singly_linked_list_node *singly_linked_list_prepend(struct singly_linked_list *list, void *data)
{
    struct singly_linked_list_node *node = malloc(sizeof(struct singly_linked_list_node));
    assert(node);
    node->data = data;
    node->next = list->head;
    list->head = node;
    return node;
}

struct singly_linked_list_node *singly_linked_list_insert_after(struct singly_linked_list_node *previous, void *data)
{
    assert(previous);
    struct singly_linked_list_node *node = malloc(sizeof(struct singly_linked_list_node));
    assert(node);
    node->data = data;
    node->next = previous->next;
    previous->next = node;
    return node;
}

struct singly_linked_list_node *singly_linked_list_append(struct singly_linked_list *list, void *data)
{
    struct singly_linked_list_node *node = malloc(sizeof(struct singly_linked_list_node));
    assert(node);
    node->data = data;
    node->next = NULL;
    if (list->head)
    {
        struct singly_linked_list_node *last = list->head;
        while (last->next)
        {
            last = last->next;
        }
        last->next = node;
    }
    else
    {
        list->head = node;
    }
    return node;
}

void singly_linked_list_remove(struct singly_linked_list *list, void *data)
{
    struct singly_linked_list_node *current = list->head;
    if (current && current->data == data)
    {
        list->head = current->next;
        free(current);
    }
    else
    {
        struct singly_linked_list_node *previous = NULL;
        while (current && current->data != data)
        {
            previous = current;
            current = current->next;
        }
        if (current)
        {
            previous->next = current->next;
            free(current);
        }
    }
}

void singly_linked_list_remove_at(struct singly_linked_list *list, int index)
{
    if (list->head)
    {
        struct singly_linked_list_node *current = list->head;
        if (index == 0)
        {
            list->head = current->next;
            free(current);
        }
        else
        {
            for (int i = 0; current && i < index - 1; i++)
            {
                current = current->next;
            }
            if (current && current->next)
            {
                struct singly_linked_list_node *next = current->next->next;
                free(current->next);
                current->next = next;
            }
        }
    }
}

int singly_linked_list_count(struct singly_linked_list *list)
{
    int count = 0;
    struct singly_linked_list_node *current = list->head;
    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}

bool singly_linked_list_contains(struct singly_linked_list *list, void *data)
{
    bool contains = false;
    struct singly_linked_list_node *current = list->head;
    while (current)
    {
        if (current->data = data)
        {
            contains = true;
            break;
        }
        current = current->next;
    }
    return contains;
}

void *singly_linked_list_get_at(struct singly_linked_list *list, int index)
{
    struct singly_linked_list_node *node = NULL;
    struct singly_linked_list_node *current = list->head;
    int current_index = 0;
    while (current)
    {
        if (current_index == index)
        {
            node = current->data;
            break;
        }
        current_index++;
        current = current->next;
    }
    return node;
}
