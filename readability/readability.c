#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text); //give an integer which is the number of letters(a to z and A to Z)
int count_words(string text); //return integer, number of words, experimental, only space is considered
int count_sentences(string text); //return the number of sentences. experimental, it directly consider '.', '?' and '!'
//                                at end of a sentence. it might not consider a text taht ends without '.'
//                                or others like a sentence so make sure to respect the grammar

int main(void)
{
    int l, w, s, grade;
    float W, L, S;
    string text = get_string("Text: ");

    l = count_letters(text);
    w = count_words(text);
    s = count_sentences(text);

    L = (l * 100.0) / w;
    S = (s * 100.0) / w;
    grade = (int) round((0.0588 * L) - (0.296 * S) - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

/*-------------------------------------------------------------------------------------------*/

int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            count++;
        }
    }
    return count;
}

/*-------------------------------------------------------------------------------------------*/

int count_words(string text)
{
    int count = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

/*-------------------------------------------------------------------------------------------*/

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}