#include "cs.h"
#include "database.h"

int main(int argc, char **argv)
{
    pid_t pid;
    pthread_t thread;

    // pid_t db_pid;
    // pthread_t db_thread;

    printf("Generated Project\n"); 

    // This works.
    // create_process(pid, thread);

    // return an array pointer to the new queue.
    int *queue = que_init(10);

    // in other words: int queue[10] = {0};
                               
    // If peek is used before any items are added to the queue, an error occurs. 

    que_insert(queue, 892);
    printf("\npeek -> [ %d ]\n", que_peek(queue));
    que_insert(queue, 100);
    que_insert(queue, 200);
    que_insert(queue, 300);
    que_insert(queue, 400);
    que_insert(queue, 500);
    que_insert(queue, 600);
    que_insert(queue, 700);

    printf("peek -> [ %d ]\n", que_peek(queue));
    printf("preview -> [ %d ]\n", que_preview(queue, 1));
    printf("preview -> [ %d ]\n", que_preview(queue, 4));
    printf("preview -> [ %d ]\n", que_preview(queue, 7));
    printf("peek last -> [ %d ]\n", que_peek_last(queue));

    free(queue);

    // call Database process
    create_db_process(pid, thread);

    return 0;
}
