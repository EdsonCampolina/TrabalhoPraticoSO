#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string.h>
#include <semaphore.h>
#include <assert.h>
#include <pthread.h>


// Char sizes

const int SIZECHARINPUT = 100;
const int SIZECHARMESSAGELOG = 100;
const int LISTSIZE = 100;
const int __HASHTABLE_LENGTH = 1024;

/**
 *@brief Simple Hash Function
 */
int HASH_FN(int x)
{
    return (x) % __HASHTABLE_LENGTH;
}

// Commands definitions

const int NOCOMMANDS = 7;
char commandsStr[NOCOMMANDS][20] = {"--insert=", "--search=", "--remove=", "--update=", "--list=", "undefined", "--reverse-list="};
char commandsTypes[NOCOMMANDS][20] = {"insert", "search", "remove", "update", "list", "undefined", "reverse-list"};
int commandsSize[NOCOMMANDS] = {9, 9, 9, 9, 7, 1, 15};
char commandsRes[NOCOMMANDS][25] = {"Inserting data.", "Searching data.", "Removing data.", "Updating data.", "Listing data.", "Unknown command", "Reverse listing data"};


// Putting all args in a char

char *concatAllArgs(int argc, char *argv[])
{
    int i, v = 0, size = argc - 1;
    char *str = (char *)malloc(v);

    for (i = 1; i <= size; i++)
    {
        str = (char *)realloc(str, (v + strlen(argv[i])));
        strcat(str, argv[i]);
        strcat(str, " ");
    }
    return str;
}

/**
 * @brief Semaphore for Hashtable
 */
static sem_t semaphore;

void SEMAPHORE_INIT(void)
{
	assert(sem_init(&semaphore, 0, 1) == 0);
}

void SEMAPHORE_DOWN(void)
{
	assert(sem_wait(&semaphore) == 0);
}

void SEMAPHORE_UP(void)
{
	assert(sem_post(&semaphore) == 0);
}

/**
 * @brief Mutex for Hashtable
 */
static pthread_mutex_t lock;

unsigned nreaders = 0;

void MUTEX_INIT(void)
{
	assert(pthread_mutex_init(&lock, NULL) == 0);
}

void MUTEX_LOCK(void)
{
	assert(pthread_mutex_lock(&lock) == 0);
}

void MUTEX_UNLOCK(void)
{
	assert(pthread_mutex_unlock(&lock) == 0);
}

static void reader_enter(void)
{
	MUTEX_LOCK();
	nreaders++;
	if (nreaders == 1)
		SEMAPHORE_DOWN();
	MUTEX_UNLOCK();
}

static void reader_leave(void)
{
	MUTEX_LOCK();
	nreaders--;
	if (nreaders == 0)
		SEMAPHORE_UP();
	MUTEX_UNLOCK();
}

#endif