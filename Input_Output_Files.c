#include <stdio.h>
#include "dbg.h"

#define MAX_DATA 100

typedef enum EyeColor {
    BLUE_EYES, GREEN_EYES, BROWN_EYES,
    BLACK_EYES, GREY_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Grey", "Other"
};

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;

int main(int argc, char *argv[])
{
    Person you = {.age = 0};
    int i = 0;
    char *in = NULL;

    printf("What's your first name? ");
    in = fgets(you.first_name, MAX_DATA - 1, stdin);
    check(in != NULL, "Failed to read first_name");

    printf("What's your last name? ");
    in = fgets(you.last_name, MAX_DATA - 1, stdin);
    check(in != NULL, "Failed to read first_name");

    printf("How old are you? ");
    int rc = fscan(stdin, "%d", &you.age);
    check(rc > 0, "You have to enter a number. ");

    printf("What's colour are your eyes:\n ");
    for (i = 0; i <= OTHER_EYES; i++)
    {
        printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
    }
    printf("> ");

    int eyes = -1;
    rc = fscanf(stdin, "%d", &eyes);

}