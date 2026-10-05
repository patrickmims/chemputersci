#include "cs.h"

static int ARRAY_SIZE = 0;
int front = -1;
int rear = -1;
int que_ptr; // Keep track of where we are in the queue.

FILE *que_error_log()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("que_error_log.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    return filePtr;
}

// create a node and return it 
static void *create_array_node(const int size)
{
    void *node = NULL;

    if((node = malloc(size * sizeof(void *))) == NULL)
        exit(EXIT_FAILURE);

    return node;
}

// -------------------------------------------------------- static int que_init(int)
// Initialize the array.
// ---------------------------------------------------------------------------------
int *que_init(const int size)
{
    ARRAY_SIZE = size;
    que_ptr = 1; // Initialize the ptr to keep track.

    int *list = (int *)create_array_node(ARRAY_SIZE), i; 

    // Initialize to zero.
    for(i = 0; i < ARRAY_SIZE; i++)
        list[i] = 0;

    return list;
}

// ----------------------------------------------------- int que_element(int *, int)
// Return the value of the next element to be dequeued without dequeueing it.
// ---------------------------------------------------------------------------------
int que_preview(int *queue, int p)
{
    if(p >= que_ptr)
    {
        printf("que_element(queue, %d) is out of range.\n", p);
        exit(EXIT_FAILURE);
    }

    return queue[p];
}

// ------------------------------------------------------ static int que_size(int *)
// Return the size of the queue.
// ---------------------------------------------------------------------------------
static int que_size(int *queue)
{
    return ARRAY_SIZE; 
}

// ------------------------------------------------------ int que_insert(int *, int)
// Return the value of the next element to be dequeued without dequeueing it.
// Every queue has Front and Rear variables that point to the position [from] where 
// deletions and insertions can be done, respectively.
// ---------------------------------------------------------------------------------
void que_insert(int *queue, int value)
{
    if(rear == ARRAY_SIZE - 1)
    {
        puts("Overflow - exit");
        exit(EXIT_FAILURE);
    } else if(front == -1 && rear == -1) { // stack is empty
        front = 0;
        rear = 0;
    } else {
        rear++;
        que_ptr++;
    }

    queue[rear] = value;

    printf("que_insert -> [ %d ]\n", value);
    printf("que_size -> [ %d ]\n", que_size(queue));
    printf("que_ptr -> [ %d ]\n\n", que_ptr);
    printf("que_peek_first -> [ %d ]\n\n", que_peek(queue));
    printf("que_peek_last -> [ %d ]\n\n", que_peek_last(queue));
}

// ------------------------------------------------------------- int que_peek(int *)
// Return the value of the next element to be dequeued without dequeueing it.
// ---------------------------------------------------------------------------------
int que_peek(int *queue)
{
    // check if the queue is empty.
    if(front == -1 || front > rear)
    {
        puts("Empty.");
        exit(EXIT_FAILURE);
    } else {
        // return the first element in the queue.
        return *queue++;
    }
}

// -------------------------------------------------------- int que_peek_last(int *)
// Return the value of the last element in the queue.
// ---------------------------------------------------------------------------------
int que_peek_last(int *queue)
{
    return queue[que_ptr - 1]; // Reduce the queue ptr by one.
}

// Add an element to the REAR of the queue. 
static void *enque()
{}

// Remove an element to the FRONT of the queue. 
static void *deque()
{}

static void que_display()
{}

// chapter 12, page 257
