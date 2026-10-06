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
    product_t node;
} list_t;

typedef struct
{
    product_t node;
} stack_t;

static void *get_memory()
{
    void *memory = NULL;

    if((memory = malloc(sizeof(void *))) == NULL)
        exit(EXIT_FAILURE);

    return memory;
}

product_t *new_node(const char *type) 
{
    if(strcmp(type, "L") == 0)
    {
        list_t *product = NULL; 
        product = (list_t *)get_memory();
        // product->node.operation = operationA;
        return (product_t *)product; 
    } else if(strcmp(type, "S") == 0) {
        stack_t *product = NULL; 
        product = (stack_t *)get_memory();
        // product->node.operation = operationB; 
        return (product_t *)product; 
    }

    return NULL;
} 
