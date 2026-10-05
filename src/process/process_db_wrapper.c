#include "cs.h"

FILE *process_db_error()
{
    FILE *filePtr;

    if((filePtr = fopen("process_db_error_log.txt", "a")) == NULL)
        fprintf(stderr, "Error: ");

    return filePtr;
}

// Run the MYSQL connection in a new process. 
// By the way, this is a remote database that we're accessing.
void create_db_process(pid_t pid, pthread_t thread)
{
    void *(*db)() = db_init; 
    switch(pid = fork())
    {
        case -1: 
            fprintf(process_db_error(), "Error: Process Database Error");
            break;
        case 0:
            db_init();
            break;
        default:
            sleep(5);
            break;
    }
}
