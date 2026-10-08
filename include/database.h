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
    char db[7];
    char host[15];
    char user[9];
    char pword[9];
    char table[10];
    int port;
} credentials_t;  

void *get_memory();
void *initialize_database();
void *db_retrieve_data(database_t *); 

#endif
