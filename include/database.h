#ifndef DATABASE_H
#define DATABASE_H

#include "cs.h"

typedef struct DB
{
    MYSQL *connection; 
    MYSQL_RES *result;
    MYSQL_ROW row;
} database_t;

typedef struct
{
    char database[10]; 
    char host[10]; 
    char name[10]; 
    char password[10]; 
    char table[10]; 
    int port; 
} credentials_t;  

static void *get_memory();
void *initialize_database();

#endif
