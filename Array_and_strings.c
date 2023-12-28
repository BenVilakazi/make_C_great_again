#include   <stdio.h>

int main(int argc, char *argv[])
{
    int num[5] = { 0 };
    char name[5] = { 'a' };

    printf(" numbers: %d %d %d %d\n", num[0], num[1], num[2], num[3]);

    printf("name: %c %c %c %c\n", name[0], name[1], name[2], name[3]);

    printf("name: %s", name);

    num[0] = 1;
    num[1] = 2;
    num[2] = 3;
    num[3] = 4;

    name[0] = 'B';
    name[1] = 'e';
    name[2] = 'n';
    name[3] = '!';
    name[4] = '\0';

    printf("numbers: %d %d %d %d\n", num[0], num[1], num[2], num[3]);

    for (int i = 0; i <= 4: i++)
    {
        putchar(name[i]);
    }
    putchar('\n');
    
    printf("name %s", name);

    char *alt = "Ben";
    printf("alt %s", alt);

    for (int i = 0; i <= 3; i++)
    {
        putchar("alternative: %s" alt);
    }
    return 0;
}