#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (only_digits(argv[1]))
    {
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Convert
    int newargv = atoi(argv[1]);

    string plain = get_string("Plaintext:\n");
    printf("ciphertext: \n");
    for (int i = 0; i < strlen(plain); i++)
    {
        printf("%c", rotate(plain[i], newargv));
    }
    printf("\n");
    //
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        char base = isupper(c) ? 'A' : 'a';
        return (c - base + n) % 26 + base;
    }
    else
    {
        return c;
    }
}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) == false)
        {
            return false;
        }
    }
    return true;
}
