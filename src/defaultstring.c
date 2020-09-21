#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_SIZE 1024 * 1024


char *load(const char *filename)
{
    char *buffer = NULL;

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

    return buffer;
}

int main(int argc, char const *argv[])
{
    char *text = load("lipsum.txt");


    long total= 0 ;

    for (size_t i = 0; i < 100000000; i++)
    {
        total += strlen(text);
    }

    printf("Lipsum text length is %ld\n",total);


    


    return 0;
}
