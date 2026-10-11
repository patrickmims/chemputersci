#include "cs.h"

FILE *json_error_log()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("json_error_log.txt", "a")) == NULL)
        fprintf(stderr, "Error: json...");

    return filePtr;
}

//-------------------------------------
// void *json_read_file(json_object *)
//
//-------------------------------------
void *json_read_file(json_object *jo)
{
    struct Object object = { "json_test_file.txt" };

    if((jo = json_object_from_file(object.file)) < 0) 
        fprintf(json_error_log(), "Error: json_object_From_file()");

    printf("%s", json_object_to_json_string(jo));
}

void json_init()
{
    json_object *root = NULL;

    json_read_file(root);

    json_object_put(root);
}
