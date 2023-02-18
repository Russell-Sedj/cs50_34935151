#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int only_digits(char text[]);
string rotate(string text, int key);

int main(int argc, string argv[])
{
    if (argc > 2 || argc < 2 || !only_digits(argv[1]))
    {
        printf("./ceasar key\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        string text = get_string("plaintext: ");

        if (key > 26)
        {
            key = key % 26;
        }

        printf("ciphertext: %s\n", rotate(text, key));
    }
}

int only_digits(char text[])
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isdigit(text[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

string rotate(string text, int key)
{
    //it was a pretty tricky task
    //i checked each letter and added +1 each time to verify if the next is after 'z' or after 'Z'
    //then when it's the case the text[i] becomes 'a' or 'A'
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            for (int j = 0; j < key; j++)
            {
                if ((text[i] + 1) == 91)
                {
                    text[i] = 'A';
                }
                else if ((text[i] + 1) == 123)
                {
                    text[i] = 'a';
                }
                else
                {
                    text[i] = text[i] + 1;
                }
            }
        }
    }
    return text;
}