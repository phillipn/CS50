/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dictionary.h"

 typedef struct node {
        char word[LENGTH +1];
        struct node* next;
    } node;
        
    node* hashtable[1000000] = {NULL};
    int dictionarysize = 0;
    
    int hash(const char* word)
    {
        int hash=0;
        int n;
    
        for(int i=0; word[i] != '\0'; i++) {
            
            if (isalpha(word[i])) {
                n = (word[i] - 'a' +1);
            } else {
                n=27;
            }
            hash = ((hash<<3)+n) % 1000000;
        } return hash;
    }

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
FILE* fp = fopen(dictionary, "r");

    if (fp == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return 1;
    }
    
    char word[LENGTH+1];
    
    while (fscanf(fp, "%s\n", word) != EOF) {
        dictionarysize ++;
        
        node* new_node = malloc(sizeof(node));
        
        strcpy(new_node->word, word);
        
        int index = hash(word);
        
        if (hashtable[index] == NULL) {
            hashtable[index]=new_node;
            new_node->next=NULL;
        } else {
            new_node->next=hashtable[index];
            hashtable[index]=new_node;
        }
        
    }
    
    fclose(fp);
    
    return true;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
   char temp[LENGTH+1];
   int len = strlen(word);
   
   for(int i=0; i<len; i++) {
      temp[i] = tolower(word[i]); 
   }
   temp[len]='\0';
   
   int index = hash(temp);
   
   if (hashtable[index] == NULL)
    return false;
    
    node* crawler = hashtable[index];
    
    while (crawler != NULL) {
        if (strcmp(temp, crawler->word)==0) {
            return true;
        }
        crawler = crawler->next;
    }
    return false;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (dictionarysize>0) {
        return dictionarysize;
    }
    else {
        return 0;
    }
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    int index=0;
    while (index<1000000) {
        if (hashtable[index] == NULL) {
            index++;
        } else {
            while (hashtable[index] != NULL) {
                node* crawler = hashtable[index];
                hashtable[index] = crawler->next;
                free(crawler);
            }
            index++;
        }
    }
   return true; 
}
