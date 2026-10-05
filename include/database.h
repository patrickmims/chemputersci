#ifndef DATABASE_H
#define DATABASE_H

#include "cs.h"

typedef struct DB
{
    MYSQL *connection; 
    MYSQL_RES *result;
    MYSQL_ROW row;
} database_t;

#endif
