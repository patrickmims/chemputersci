#include "cs.h"
#include "database.h"

// zetcode.com/db/mysqlc/

void *db_insert(){}
void *db_read(){}

FILE *database_error_log()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("database_error_log.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    return filePtr;
}

typedef struct credentials 
{
    char *name;
    char *server;
} credentials_t;

credentials_t c;
credentials_t *credentials = &c;

void *db_init()
{
    puts("* * * * * *");
    puts("*db_init() begin");
    puts("* * * * * *");

    int i;
    int num_fields;

    unsigned int port = 3306;

    database_t db; 
    database_t *database = &db;

    database->connection = mysql_init(NULL);

    if((database->connection = mysql_init(NULL)) == NULL)
        fprintf(database_error_log(), "Error: Database...\n");

    if(mysql_real_connect(database->connection, "192.168.1.183", "patrick", "2gdx429", "alpaca", port, NULL, 0) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(database->connection));
        mysql_close(database->connection);
        exit(1);
    }

    if(mysql_query(database->connection, "SELECT * FROM fidelity"))
    {
        fprintf(stderr, "%s\n", mysql_error(database->connection));
        mysql_close(database->connection);
        exit(1);
    }

    if((database->result = mysql_store_result(database->connection)) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(database->connection));
        mysql_close(database->connection);
        exit(1);
    }

    num_fields = mysql_num_fields(database->result);

    printf("num_fields: %d\n", num_fields);

    while((database->row = mysql_fetch_row(database->result)))
    {
        for(i = 0; i < num_fields; i++)
            printf("%s ", database->row[i] ? database->row[i] : "NULL"); 

        printf("\n");
    }

    mysql_free_result(database->result);
    mysql_close(database->connection);

    puts("* * * * * *");
    puts("*db_init() end");
    puts("* * * * * *");

    return 0;
}
