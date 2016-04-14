#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i=0;
    int n=0;

    do
    {
        printf("Height:");
        n=GetInt();
    } while (n<0 || n>23);

    for (i=0; i<n; i++)
    {
        for (int y=n; y>=i+2; y--)
        {
            printf(" ");
        }
        for (int x=0; x<i+2; x++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}