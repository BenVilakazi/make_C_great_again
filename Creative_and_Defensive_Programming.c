#undef NDEBUG
#include "dbg.h"
#include <stdio.h>
#include <assert.h>

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

int safercopy(int from_len, char *from, int to_len, char *to)
{
    assert(from != NULL && to != NULL && "from and to can't be NULL");
    int i = 0;
    int max = from_len > to_len - 1 ? to_len - 1 : from_len;

    if (from_len < 0 || to_len <= 0)
        return -1;

    for (i = 0; i < max; i++)
    {
        to[i] = from[i];
    }

    to[to_len - 1]
}