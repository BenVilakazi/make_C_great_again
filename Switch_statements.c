#include <stdio.h>
/* Switch Statements */
int main(void)
{
    int i = 0;

    for (i = 1; i < argc; i++)
    {
        printf("arg %d: %s\n",i , argv[i]);
    }

    char *provinces[] = 
    {
        "North West", "Eastern Cape", "Western Cape", "Limpopo"
    };

    int num_provinces = 4;

    for (i = 0; i < num_provinces; i++)
    {
        printf("Province %d: %s\n", i, provinces[i]);
    }

    return 0;
}