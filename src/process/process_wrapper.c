#include "cs.h"

/**
 * create a new process and run a background thread - create_thread(...);
 *
 */

void create_process(pid_t pid, pthread_t thread)
{
    // no need to cast here, this is done in the thread.
    // struct list *head = (struct list *)create_node; <- Do not do here!
    struct list *head = NULL; 

    switch(pid = fork())
    {
        case -1: 
            fprintf(process_error_log(), "Error: Process Error");
            break;
        case 0: 
            puts("create_process...");
            // function pointer.
            // has a (void *) param because I'm passing in a data structure.
            void *(*fn)(void *) = libcurlHTTP;
            create_thread(thread, fn, head);
            break;
        default: 
            sleep(5);
            break;
    }

    exit(EXIT_SUCCESS); // Terminate the process.
}

/* System Calls -
 *
 * execve(), exit(), fork() and wait() 
 *
 *
 *
 * */
