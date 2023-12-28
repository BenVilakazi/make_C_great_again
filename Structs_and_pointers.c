#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name,  int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != .NULL)
}
