#ifndef CS_H
#define CS_H

#include <curl/curl.h>
#include <mysql.h>
#include <mysqld_error.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define INDEX_SIZE 10
struct element 
{
    int id;
    int atomic_number;
    char symbol[1];
    char name[INDEX_SIZE];
    char slug[INDEX_SIZE];
    char category[INDEX_SIZE];
};

typedef struct LIBCURL
{
    CURL *curl;
    CURLcode code;
    curl_off_t fsize;
    struct stat file_info;
} libcurl_t;

struct Memory
{
    char *memory;
    size_t size;
};

struct node
{
    // int id;
    //int atomic_number;
    //char symbol[1];
    //char name[20];
    /* use a struct to point to the data in the node, 
     * not sure if this is good or bad, but it works.*/
    struct element elem;
    struct node *next;
};

FILE *linkedlist_error_log();
FILE *process_error_log();
void *create_node();
void *libcurlHTTP(); 
void create_process(pid_t, pthread_t);
void create_db_process(pid_t, pthread_t);
void create_thread(pthread_t, void *(*fn)(), void *);
void insert(struct node **, int, int, char *, char *, char *, char *);

// Database
void *db_init();
void *db_insert();
void *db_read();

// Queue
int *que_init(const int);
void que_insert(int *, int);
int que_peek(int *);
int que_peek_last(int *);
static int que_size(int *);
static void que_display(int *);

int que_preview(int *, int);

static void *enque(int *);
static void *deque(int *);

static int *que_set_front(int);
static int *que_set_rear(int);

#endif
