#include "cs.h"
#include "database.h"

// ------------------------------------------------void *initialize_database_error()
// -------------------------------------------------------------------------------
FILE *initialize_database_error()
{
    FILE *logPtr = NULL;

    if((logPtr = fopen("database_init_error_log.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    return logPtr;
}

// -------------------------------------------------------------void *get_memory()
// Utility function that returns heap memory.
// -------------------------------------------------------------------------------
void *get_memory()
{
    void *memory = NULL;

    if((memory = malloc(sizeof(void *))) == NULL)
        fprintf(initialize_database_error(), "Error: Initializing Database.");

    return memory;
}

/*
void *db_create_table(datab)
{
}
*/

// -----------------------------void *db_retrieve_data(credentials_t, database_t *)

void *db_retrieve_data(database_t *d)
{
    int i, num_fields;

    if(mysql_query(d->connection, "select * from fidelity"))
        fprintf(stderr, "error:...");

    if((d->result = mysql_store_result(d->connection)) == NULL)
        exit(EXIT_FAILURE);

    while((d->row = mysql_fetch_row(d->result)))
    {
        for(i = 0; i < mysql_num_fields(d->result); i++)
            printf("%s ", d->row[i] ? d->row[i] : "NULL");

        printf("\n");
    }
}

// -----------------------------------------------------void *initialize_database()

void *initialize_database()
{
    credentials_t credentials = { 
        // "database", "host", "user", "pword", "table", 3306
    };

    database_t d;
    database_t *database = &d;

    if((database->connection = mysql_init(NULL)) == NULL)
        fprintf(initialize_database_error(), "Error: connection error.");

    if(mysql_real_connect(database->connection, 
                credentials.host, 
                credentials.user, 
                credentials.pword, 
                credentials.db, 
                credentials.port, NULL, 0) == NULL) 
    {
        fprintf(stderr, mysql_error(database->connection));
        mysql_close(database->connection);
        exit(EXIT_FAILURE);
    }

    db_retrieve_data(database);

    mysql_free_result(database->result);
    mysql_close(database->connection);

    exit(0);
}
