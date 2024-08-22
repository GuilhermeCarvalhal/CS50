#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i) == true)
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    int cont = 0;
    for(int i = 2; i <= number; i++)
    {

        if (number % i == 0)
        {
            cont++;
        }
    }
    if (cont == 1)
    {
        return true;
    }
    return false;
}
