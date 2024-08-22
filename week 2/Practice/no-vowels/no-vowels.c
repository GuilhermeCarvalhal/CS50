// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool one_ca(int g, string s);
string replace(string v);


int main(int argc, string argv[])
{
    if (one_ca(argc, argv[1]) == false)
        {
            printf("./no-vowels word\n");
            return 1;
        }
    else
    {
        printf("%s\n", replace(argv[1]));
    }

}




string replace(string v)
{
    for (int i = 0; i < strlen(v); i++)
    {
        switch (v[i])
        {
            case 'a':
                v[i] = '6';
                break;

            case 'e':
                v[i] = '3';
                break;

            case 'i':
                v[i] = '1';
                break;

            case 'o':
                v[i] = '0';
                break;
        }
    }
    return v;
}


bool one_ca(int g, string s)
{
    if (g != 2)
        {
            return false;
        }
    return true;
}

