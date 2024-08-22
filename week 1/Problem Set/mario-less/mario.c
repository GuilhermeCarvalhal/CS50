#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Gets the size with a maximum input
    int size = 0;
    while (size <= 0 || size >= 9)
    {
        size = get_int("Size: \n");
    }

    for (int i = 1; i <= size; i++)
    {
        // Print the dots based on the size
        for (int c = 0; c < size - i; c++)
        {
            printf(" ");
        }
        // Print the hashs
        for (int b = 0; b < i; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}
