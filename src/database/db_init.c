#include "cs.h"
#include "database.h"

FILE *initialize_database_error()
{
    FILE *logPtr = NULL;

    if((logPtr = fopen("database_init_error_log.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    return logPtr;
}

void *get_memory()
{
    void *memory = NULL;

    if((memory = malloc(sizeof(void *))) == NULL)
        fprintf(initialize_database_error(), "Error: Initializing Database.");

    return memory;
}

void *initialize_database()
{
    credentials_t c;
    credentials_t *credentials = &c;

    database_t d;
    database_t *database = &d;

    credentials = (credentials_t *)get_memory();
    database = (database_t *)get_memory();

    strncpy(credentials->database, "alpaca" ,sizeof(credentials->database));
    strncpy(credentials->host, "xxxxxx" ,sizeof(credentials->host));
    strncpy(credentials->name, "xxxxxx" ,sizeof(credentials->name));
    strncpy(credentials->password, "xxxxxx" ,sizeof(credentials->password));
    strncpy(credentials->table, "fidelity" ,sizeof(credentials->table));

    credentials->port = 3306;

    database->connection = mysql_init(NULL);

    if(database->connection == NULL)
    {
        fprintf(initialize_database_error(), "Error: connection error.");
        exit(1);
    }

    if(mysql_real_connect(database->connection, credentials->host, credentials->name, credentials->password, credentials->database, credentials->port, NULL, 0) == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(database->connection));
        mysql_close(database->connection);
        exit(1);
    }

    mysql_close(database->connection);

    puts("Initialize Database");

    exit(0);
}
