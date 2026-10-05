#include "cs.h"

// https://curl.se/libcurl/c/getinmemory.html

// create a function to handle the error logging.
static FILE *libcurl_error_log()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("libcurl_error_log.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    return filePtr;
}

static size_t write_callback(char *data, size_t size, size_t nmemb, void *arg)
{
    puts("write_callback 1");

    size_t realsize = (size * nmemb);

    struct Memory m; // create a reference to the structure.
    struct Memory *mem = &m; // create a pointer to the reference.

    mem = (struct Memory *)arg;  // cast the data type to the data type we want.

    char *filePtr = NULL;

    if((filePtr = realloc(mem->memory, mem->size + realsize + 1)) == NULL)
    {
        printf("not enough memory");
        exit(EXIT_FAILURE);
    }

    // libcurl documentation, I didn't write.
    mem->memory = filePtr;
    memcpy(&mem->memory[mem->size], data, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    puts("write_callback 2");

    return realsize;
}

void *libcurlHTTP(void *list)
{
    libcurl_t lc; 
    libcurl_t *libcurl = &lc;

    struct Memory m;
    m.memory = malloc(1);
    m.size = 0;

    // struct Memory *mem = &m;

    // struct Memory *memory = &m;
    // memory = (struct Memory *)create_node();

    //memory_t m;

    // Uncomment this to use api.periodictableofelements.org/api/elements/
    // int atnum = 11;
    // char url[] = "https://api.periodictableofelements.org/api/elements/";

    char url[] = "https://www.thecocktaildb.com/api/json/v1/1/search.php?s=margarita";

    if(libcurl->code = curl_global_init(CURL_GLOBAL_ALL) < 0)
        fprintf(libcurl_error_log(), "Error: curl_global_init()");

    libcurl->curl = curl_easy_init();

    if(libcurl->curl == NULL)
        exit(EXIT_FAILURE);

    // Uncomment this to use api.periodictableofelements.org/api/elements/
    // sprintf(url + strlen(url), "%d", atnum); // Append atomic number to api.
    // strncat(url, "?format=api", sizeof(url) - strlen(url) - 1);

    printf("[ %s ]\n", url);

    curl_easy_setopt(libcurl->curl, CURLOPT_URL, url);
    curl_easy_setopt(libcurl->curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(libcurl->curl, CURLOPT_WRITEDATA, (void *)&m);
    curl_easy_setopt(libcurl->curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    libcurl->code = curl_easy_perform(libcurl->curl);

    printf("libcurl->code %d\n", libcurl->code);

    if(libcurl->code != CURLE_OK)
        fprintf(stderr, "C.E failed: %s\n", curl_easy_strerror(libcurl->code));

    printf("%lu bytes retrieved\n", (unsigned long)m.size);

    curl_easy_cleanup(libcurl->curl);

    free(m.memory);
    curl_global_cleanup();

    int r = 3, c = 4;
    // create an array of structures: 

    // Test Data.
    int id = 11;
    int atomic_number = 11; 
    char symbol[] = "NA";
    char name[] = "Sodium";
    char slug[] = "sodium";
    char category[] = "alkali_metal";

    // Struct list *head was defined in process_wrapper.c, cast here. 
    list = (struct node *)create_node(); 

    insert(list, id, atomic_number, symbol, name, slug, category);

    puts("libcurlhttp()");
}
