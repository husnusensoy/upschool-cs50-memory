#include<stdlib.h>
#define MB 1024 * 1024

int main(int argc, char const *argv[])
{
    int *bigheap = malloc(sizeof(int) * 16* MB);

    if (bigheap == NULL){
        exit(EXIT_FAILURE);
    }


    for (int i = 0; i < 1 * MB; i++)
    {
        bigheap[i] = -1;
    }

    
    
    return 0;
}
