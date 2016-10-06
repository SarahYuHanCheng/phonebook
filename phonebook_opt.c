include <stdlib.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
/*Construct hash talbe*/
hashTable *hashInitial()
{
    hashTable *ht = NULL;
    ht = (hashTable *)malloc(sizeof(hashTable));
    ht->list = (entry**)malloc(sizeof(entry *)*HASHTABLE_SIZE);
    for (int i = 0; i< HASHTABLE_SIZE; i++)
        ht->list[i] = NULL;

    return ht;
}

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131;
    // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    while (*str)
        hash = hash * seed + (*str++);

    return hash % HASHTABLE_SIZE;
}

/* hash version */
entry *hashFindName(char  lastName[], entry *pHead[])
{
	unsigned int n = BKDRHash(lastName);
    entry *e;
    e = pHead[n]->pNext;
    while (e != NULL) {
        if (strcasecmp(lastName,e->lastName) == 0)
            return e;
        e = e->pNext;
    }
    return NULL;
}
int *hashAppend(char *lastName, entry *newEntry[])
{
    /* allocate memory for the new entry and put lastName */

    unsigned int n = BKDRHash(lastName);
   
    newEntry[n]->pNext = (entry *)malloc(sizeof(entry));
    newEntry[n]= newEntry[n]->pNext;
    strcpy(e[n]->lastName, lastName);
    newEntry[n]->pNext = NULL;
    
}


entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{

    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}

