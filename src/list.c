#include "list.h"

#include <assert.h>
#include <malloc.h>
#include <stddef.h>

list_t *list_new(void)
{
    list_t *l = malloc(sizeof(list_t));
    assert(l);
    l->head = NULL;
    l->tail = NULL;
    return l;
}

void list_delete(list_t *l)
{
    list_node_t *curr = l->head;
    while (curr)
    {
        list_node_t *next = curr->next;
        free(curr);
        curr = next;
    }
    free(l);
}

list_node_t *list_prepend(list_t *l, void *data)
{
    list_node_t *n = malloc(sizeof(list_node_t));
    assert(n);
    n->data = data;
    n->next = l->head;
    n->prev = NULL;
    if (l->head)
    {
        l->head->prev = n;
    }
    else
    {
        l->tail = n;
    }
    l->head = n;
    return n;
}

list_node_t *list_insert_after(list_t *l, list_node_t *prev, void *data)
{
    assert(prev);
    list_node_t *n = malloc(sizeof(list_node_t));
    assert(n);
    n->data = data;
    n->next = prev->next;
    prev->next = n;
    n->prev = prev;
    if (n->next)
    {
        n->next->prev = n;
    }
    if (prev == l->tail)
    {
        l->tail = n;
    }
    return n;
}

list_node_t *list_append(list_t *l, void *data)
{
    list_node_t *n = malloc(sizeof(list_node_t));
    assert(n);
    n->data = data;
    n->next = NULL;
    if (l->head)
    {
        list_node_t *last = l->head;
        while (last->next)
        {
            last = last->next;
        }
        last->next = n;
        n->prev = last;
    }
    else
    {
        n->prev = NULL;
        l->head = n;
    }
    l->tail = n;
    return n;
}

void list_remove(list_t *l, list_node_t *n)
{
    if (!l->head || !n)
    {
        return;
    }
    if (l->head == n)
    {
        l->head = n->next;
    }
    if (l->tail == n)
    {
        l->tail = n->prev;
    }
    if (n->next)
    {
        n->next->prev = n->prev;
    }
    if (n->prev)
    {
        n->prev->next = n->next;
    }
    free(n);
}

int list_count(list_t *l)
{
    int c = 0;
    list_for_each(l, n)
    {
        c++;
    }
    return c;
}

bool list_contains(list_t *l, void *data)
{
    list_for_each(l, n)
    {
        if (n->data == data)
        {
            return true;
        }
    }
    return false;
}

void *list_get(list_t *l, int idx)
{
    int i = 0;
    list_for_each(l, n)
    {
        if (i == idx)
        {
            return n->data;
        }
        i++;
    }
    return NULL;
}

void list_reverse(list_t *l)
{
    list_node_t *head = l->head;
    list_node_t *temp = NULL;
    list_node_t *curr = l->head;
    while (curr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
    {
        l->head = temp->prev;
    }
    l->tail = head;
}
