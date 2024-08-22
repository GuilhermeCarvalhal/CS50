#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string tex);
int count_sentences(string tex);
int get_grade(float let, float wor, float sen);

int main(void)
{
    string text = get_string("Text: \n");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = get_grade(letters, words, sentences);

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int get_grade(float let, float wor, float sen)
{
    float L = (let / wor) * 100;
    float S = (sen / wor) * 100;
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}

int count_sentences(string tex)
{
    int s = 0;
    for (int i = 0; i < strlen(tex); i++)
    {
        if (tex[i] == '?' || tex[i] == '!' || tex[i] == '.')
            s++;
    }
    return s;
}

int count_words(string tex)
{
    int w = 0;
    // will contain at least one word;
    // will not start or end with a space; and
    // will not have multiple spaces in a row.
    for (int i = 0; i < strlen(tex); i++)
    {
        if ((isalpha(tex[i]) && isblank(tex[i + 1])) || (ispunct(tex[i]) && isblank(tex[i + 1])) || (tex[i] == '.'))
        {
            w++;
        }
    }
    return w;
}

int count_letters(string tex)
{
    int l = 0;

    for (int i = 0; i < strlen(tex); i++)
    {
        if (isalpha(tex[i]))
        {
            l++;
        }
    }
    return l;
}
