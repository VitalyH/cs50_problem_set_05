// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

typedef struct node
{
    bool is_word;
    struct node *letters[27];
}
node;

node *root;

// Free node from bottom to top, recursively
void freeing(node *letters)
{
    for (int i = 0; i < 27; i++)
    {
        if (letters->letters[i] != NULL)
        {
            freeing(letters->letters[i]);
        }
    }

    free(letters);
}

// Variable for counting size of a dictionary
int dictionarySize = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index;

    // Create a pointer to a first node
    node *trav = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        // Special check for an apostrophe
        if (word[i] == '\'')
        {
            index = 26;
        }
        else

            // Convert each letter to an index, e.g a is 0
        {
            index = tolower(word[i]) - 'a';
        }

        // Traverse to next letter
        trav = trav->letters[index];

        // If NULL, word is misspelled
        if (trav == NULL)
        {
            return false;
        }
    }

    // At the end of word check if is_word is true
    if (trav->is_word == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Loads dictionary into memory.  Returns true if successful else false.
bool load(const char *dictionary)
{
    // Open the dictionary
    FILE *fp = fopen(dictionary, "r");
    int index;
    char word[LENGTH + 1];

    // ELSE fail
    if (fp == NULL)
    {
        return false;
    }

    // Creat tree
    // Initialize default value & pointer
    root = malloc(sizeof(node));
    root->is_word = false;
    for (int j = 0; j < 27; j++)
    {
        root->letters[j] = NULL;
    }

    // Build with loop
    // Scan each word
    while (fscanf(fp, "%s\n", word) != EOF)
    {
        // Create a traversal pointer from the start
        node *trav = root;

        // For every dictionary word, iterate through tree
        for (int i = 0; word[i] != '\0'; i++)
        {

            // If letter is apostrophe
            if (word[i] == '\'')
            {
                index = 26;
            }
            else

                // Convert each letter to an index
            {
                index = tolower(word[i]) - 'a';
            }

            if (trav->letters[index] == NULL)
            {

                // if NULL, malloc new node
                node *new_node = malloc(sizeof(node));
                new_node->is_word = false;
                for (int k = 0; k < 27; k++)
                {
                    new_node->letters[k] = NULL;
                }
                trav->letters[index] = new_node;
            }
            trav = trav->letters[index];
        }

        // At end of the word, set is_word true;
        trav->is_word = true;
        dictionarySize++;
    }

    fclose(fp);
    return true;
}

// Returns number of words in dictionary
unsigned int size(void)
{
    return dictionarySize;
}

// Unloads dictionary from memory
bool unload(void)
{
    node *trav = root;
    freeing(trav);
    return true;
}