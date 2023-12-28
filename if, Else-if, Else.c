#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 1) 
    {
        printf("You don't have enough arguments, please enter more arguments");
    }
    else if (argc > 1 && argc < 4)
    {
        printf("Here are you arguments:|\n ")

        for (i = 0; i < argc; i++)
        {
            printf("%s", argv[i]);
        }
        printf("\n");
    else
    {
        printf("You have too many arguments");
    }
    }
    return 0;
}