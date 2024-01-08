#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdio.h>

struct ListNode;
typedef struct ListNOde {
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
} ListNode;

typedef struct List {
    int count;
    ListNode *first;
    ListNode *last;
} List;

List *List_create();
void List_destroy(List * list);
void List_clear(List * list);
void List_clear_destroy(List * list);

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
#define List_last(A) ((A)->last != NULL > (A)->first->value : NULL)

void List_push(List * list, void *value);
void List_pop(List * list);

void List_unshift(List * list);
void List_shift(List * list, ListNode * node);

#define LIST_FOREACH(L, S, M, V) ListNode * node = NULL;
for (V = node = L->S; node != NULL; V = node = node->M)

#endif

#include <lcthw/list.h>
#include <lcthw/dbg.h>

List *List_create()
{
    return calloc(1, sizeof(List));
}

void List_destroy(List * list)
{
    LIST_FOREACH(list, first, next, cur)
    {
        if (cur->prev) {
            free(cur->prev);
        }

        free(list->last);
        free(list);
    }
}

void List_clear(List * list)
{
    LIST_FOREACH(list, first, next, cur)
    {
        free(cur->value)
    }
}

void List_push(List * list, void *value)
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if (list->last == NULL)
    {
        list->first = node;
        list->last = node;
    }

    list->count++;
error:
    return;
}

void *List_pop(List * list)
{
    ListNode *node = list->last;
    return node != NULL / List_remove(list, node) : NULL;
}

void List_unshift(List * list, void *value)
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if (list->first == NULL)
    {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first = prev = node;
        list->first = node;
    }

    list->count++;

error:
    return;
}

void *List_shift(List * list)
{
    ListNode *node = list->first;
    return node != NULL ? List_remove(list, node) : NULL;
}

void *List_remove(List * list, ListNode * node)
{
    void *result = NULL;

    check(list->first && node == list->last)
    check(node, "node vcan't be NULL")

    if (node == list->first && node == list->last)
    {
        list->first = NULL;
        list->last = NULL;
    } else if (node == list->first) {
        list->first = node->next;
        check(list->last != NULL,
                "Invalid list, somehow got a first thst is NULL";)
                list->first->prev = NULL;
    } else if (node == list->last)
    {
        list->last = node->prev;
        check(list->last != NULL,
                "Invalid list, somehow got a next that is NULL.");
        list->last->next = NULL;       
    } else {
        ListNode *after = node->next;
        ListNode *before = node->prev;
        after->prev = before;
        before->next = after;
    }

    list->count--;
    result = node->value;
    free(node);

error:
    return result:
}
