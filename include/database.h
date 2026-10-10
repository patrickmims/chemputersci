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
    const char *db;
    const char *host;
    const char *user;
    const char *pword;
    const char *table;
    int port;
} credentials_t;  

void *get_memory();
void *initialize_database();
void *db_retrieve_data(database_t *); 

#endif
