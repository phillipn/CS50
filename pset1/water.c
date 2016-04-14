#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("How many minutes do you shower for on average?\n");
    int min = GetInt();
    int bot = min*12;
    printf("You are using approximately %i bottles of water per session\n", bot);
}