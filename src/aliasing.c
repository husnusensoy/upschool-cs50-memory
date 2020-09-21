#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 1024

char *get_string(const char *prompt)
{
    char *buffer = NULL;

    buffer = malloc(sizeof(char) * MAX_STRING_SIZE);

    printf("%s", prompt);

    fgets(buffer, MAX_STRING_SIZE, stdin);

    size_t length = strlen(buffer);

    buffer = realloc(buffer, sizeof(char) * (length - 1)); // Trim the new line
    buffer[length] = '\0';

    return buffer;
}

int main(int argc, char const *argv[])
{
    char *s = get_string("s: ");

    char *t = s;

    printf("Length of string: %lu", strlen(s));
    for (int i = 0; i < strlen(s) + 1; i++)
    {
        t[i] = toupper(s[i]);
    }

    printf("\nText on s: %s\n", s);
    printf("Text on t: %s\n", t);

    free(s);

    return 0;
}
