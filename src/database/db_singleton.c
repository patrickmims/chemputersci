/*
    Problem: 
    There are several files that can access the database. 
    So I would like to implement a Single that accesses the credentials once 
    for all of the remaining calls in the session. (until the program ends)

    Ideally, I would like to run the program and using a switch statement 
    continuously run the program and run a different feature: insert, create etc. 
    db_init will create and initialize the singleton.
*/

#include "cs.h"

// list interface
typedef struct 
{
    void (*operation)(void);
} product_t;

typedef struct
{
    product_t base;
} list_t;

typedef struct
{
    product_t base;
} stack_t;

product_t *create_node(const char *type) 
{
    
   return NULL; 
} 
