#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *buffer;
    unsigned long length;
} string;


string* create_string(const char* cstring){

    unsigned long length_cstring = strlen(cstring);

    string *obj = malloc(length_cstring * sizeof(string));
    obj->buffer = malloc(sizeof(char) * (length_cstring+1));

    memcpy(obj->buffer, cstring, sizeof(char) * (length_cstring+1));
    obj->length = length_cstring;

    return obj;
}

//unsigned long length_string(const string* s){
//    return s->length;
//}

#define bstrlen(s) ( (s)->length ) 


string* load(const char *filename)
{
    char *buffer = NULL;
    string *str = NULL;

    FILE *fp = fopen(filename, "r");
    

    if (fp == NULL){
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);  /* same as rewind(f); */


    buffer = malloc(sizeof(char) * (fsize+1));

    fread(buffer, 1, fsize, fp);

    fclose(fp);

    buffer[fsize] = '0';

    str = create_string(buffer);

    free(buffer);

    return str;
}

int main(int argc, char const *argv[])
{
    string *text = load("lipsum.txt");


    long total= 0 ;

    for (size_t i = 0; i < 100000000; i++)
    {
        total += bstrlen(text);
    }

    printf("Lipsum text length is %ld\n",total);


    


    return 0;
}
