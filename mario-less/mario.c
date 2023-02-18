#include <cs50.h>
#include <stdio.h>

/*
i put a lot a loop but that's the only way i understood it. i'd really like to see
some others cleaner way to do it
*/

int main(void)
{
    int n = 1, height = 0;

    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < height - n; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
        n++;
    }
}