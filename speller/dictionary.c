// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
// const unsigned int N = 17576;
const unsigned int N = 100000;

// Hash table
node *table[N];

// special add: and external value to keep track of the number of the size of the dicitonary
// it will get increased in the load function. each time the fscanf reach a new word
unsigned int dico_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int x = hash(word);
    node *cursor = table[x];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // i want to consider the first trhee letters. there is 26letters in alphabet so 26^3 = 17576, the value of N
    // each first letters will have 26^2 = 676 cases before the next letter. example first letter A is
    // between 0 and 675, first B is between 676 and the next ...
    // when it find the range of the first letter. it look for the range of the second letter. which is 26^1 = 26
    // then each secon letter has a range of 26. AA? will get 0 , AB? = 26, AC? = 52, AZ? = 650 (notice that 650 + 26 = 676
    // which is the starting point og the next first letter)
    // same logic for the third. it will have a range of 26^0 = 1 so each thrid ltter will only have one case so
    // AAA is directly 0, AAB = 1, AAC = 2, AAZ = 25, ABA = 26...
    // we considered the case where the word have only one or 2 letters too that's why there are condidtions

    // finally my hash idea didn't work and i was tired of that so i just used the easy way and it worked.

    // unsigned int x;
    // int first = toupper(word[0]) - 'A', second, third;
    // if (strlen(word) == 1)
    // {
    //     x = first + (first * 676);
    // }
    // else if (strlen(word) == 2)
    // {
    //     second = toupper(word[1]) - 'A';
    //     x = (first + (first * 676)) + (second + (second * 26));
    // }
    // else
    // {
    //     second = toupper(word[1]) - 'A';
    //     third = toupper(word[2]) - 'A';
    //     x = (first + (first * 676)) + (second + (second * 26)) + third;
    // }
    // return x;

    long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        fprintf(stderr, "can't open %s", dictionary);
        return false;
    }
    char line[LENGTH + 1];
    node *n;
    while (fscanf(file, "%s", line) != EOF)
    {
        n = malloc(sizeof(node));
        if (n == NULL)
        {
            fprintf(stderr, "can't allocate memory");
            return false;
        }
        strcpy(n->word, line);
        int x = hash(line);
        n->next = table[x];
        dico_size++;
        table[x] = n;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dico_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // each case of the tab table is a linked list. so we take care of a case of table one by one. if we reach the
    // NULL value and if the i reach the last value then we can return true
    node *cursor, *temp;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
