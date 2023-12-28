#include <stdio.h>
/* Variables and Types */

int main()
{
    int distance = 100;
    float pi = 3.14;
    double super_power = 56789.4326;
    char letter = 'a';
    char name[] = "James";
    char role[] = " the instigator ";

    printf("You are %dkm away \n", distance);
    printf("You have the value of pi %f\n", pi);
    printf("You have %f super  powers\n", super_power);
    printf("The first letter of the alphabet is %c\n", letter);
    printf("We recently employed a guy named %s%s\n", name, role);
    
    int bugs = 100;
    double bug_rate = 1.2;

    printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);

    long universe_of_defects = 1L * 1024L * 1024L * 1024L;
    printf("The entire universe has %ld bugs.\n", universe_of_defects);

    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %f bugs in the system\n", expected_bugs);

    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the universe\n", part_of_universe);

    char null_byte = '\0';
    int care_perc = bugs * null_byte;
    printf("Which means you should care %d%%\n", care_perc);

    return 0;

}