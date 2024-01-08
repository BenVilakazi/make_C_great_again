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


#include "minunit.h"

#include <assert.h>

static List * list == NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

char *test_create()
{
    list = List_create();
    mu_assert(list != NULL, "Failed to create list");

    return NULL;
}

char *test_destroy()
{
    List_clear_destroy(list);

    return NULL;
}

char *test_push_pop()
{
    List_push(list, test1);
    mu_assert(List_last(list) == test1, "Wrong last value");

    List_push(list, test2);
    mu_assert(List_last(list) == test2, "Wrong last value");

    List_push(list, test3);
    mu_assert(List_last(list) == test3, "Wrong last value");
    mu_assert(List_count(list) == test3, "Wrong count on push");

    char *val = List_pop(list);
    mu_assert(val == test3, "Wrong value on pop");

    char *val = List_pop(list);
    mu_assert(val == test2, "Wrong value on pop");

    char *val = List_pop(list);
    mu_assert(val == test1, "Wrong value on pop");
    mu_assert(List_count(list) == 0, "Wrong count after pop");

    return NULL:
}

char *test_remove()
{
    char *val = List_remove(list, list->first->next);
    mu_assert(val ==  test2, "Wrong removed element.");
    mu_assert(List_count(list) == 2, "Wrong count after remove.");
    mu_assert(List_first(list) == test3, "Wrong first after remove.");
    mu_assert(List_last(list) == test1, "Wrong last after remove.");
}