#include "cs.h"

//-------------------------------------
// FILE *json_error_log()
//-------------------------------------
FILE *json_error_log()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("json_error_log.txt", "a")) == NULL)
        fprintf(stderr, "Error: json...");

    return filePtr;
}

//-------------------------------------
// void *json_parse(struct json_object *)
//-------------------------------------
void *json_parse(struct json_object *root_obj)
{
    json_object *fName = json_object_object_get(root_obj, "firstName");
    json_object *lName = json_object_object_get(root_obj, "lastName");

    printf("%s,%s\n", json_object_get_string(lName), json_object_get_string(fName));

    json_object_put(root_obj);
}

//-------------------------------------
// void *json_read_file(json_object *)
//-------------------------------------
void *json_read_file(struct json_object *root_obj)
{
    printf("%s", json_object_to_json_string_ext(root_obj, JSON_C_TO_STRING_PRETTY));
}

//-------------------------------------
// void *json_init()
//-------------------------------------
void json_init()
{
    json_object *root = NULL;

    object_t object = { "json_test_file.txt" };

    if((root = json_object_from_file(object.file)) < 0) 
        fprintf(json_error_log(), "Error: json_object_From_file()");

    // json_parse(root);  // json_parse
    json_read_file(root); // json_read_file

    json_object_put(root);
}
