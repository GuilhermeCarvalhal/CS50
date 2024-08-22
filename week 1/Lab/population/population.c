#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n;
    do
    {
        n = get_int("Initial size: ");
    }
    while (n < 9);

    // TODO: Prompt for end size
    int n2;
    do
    {
        n2 = get_int("End size: ");
    }
    while (n2 < n);

    // TODO: Calculate number of years until we reach threshold
    int finalyear = 0;
    if (n2 > n)
    {

        for (int year = 0; n < n2; year++)
        {
            n = n + (n / 3) - (n / 4);

            finalyear++;
        }
    }

    // TODO: Print number of years
    printf("Years: %i\n", finalyear);
}
