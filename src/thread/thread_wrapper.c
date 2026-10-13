#include "cs.h"

void create_thread(pthread_t thread, void *(*fn)(), void *arg)
{
    void *result;

    // fn is passed the 'arg' param as void
    // so we have to cast it as a struct in libcurl.c
    // arg will be cast a structure (linkedlist).
    if (pthread_create(&thread, NULL, fn(arg), arg) != 0)
        fprintf(stderr, "Error: pthread_create()");

    int s = pthread_join(thread, &result); // 1. wait for the thread to finish.

    printf("create_thread() - [ %d ] \n", s);

}
