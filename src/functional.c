#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int reduce(int *integers, int n, int(*lambda)(int,int), int initializer){
    return 0;
}

int* map(int *integers, int n, int(*lambda)(int)){
    return 0;
}

int* filter(int *integers, int n, int(*lambda)(int), int *m) 
{ 
    int *filtered = malloc(sizeof(n) * n);
    
    int j = 0;

    if (filtered == NULL){
        exit(EXIT_FAILURE);
    }

    memset(filtered,0, n);

    

    for (int i = 0; i < n; i++)
    {
        if (lambda(integers[i]) == 1){

            filtered[j++] = integers[i];
        }
    }

    filtered = realloc(filtered, sizeof(int) * j);

    *m = j;

    return filtered;
    
} 

int even(int x){
    if (x%2 == 0){
        return 1;
    }else{
        return 0;
    }
}

int odd(int x){
    return x%2 == 1;
}

int is_prime(int x){
    
    for (int div = 2; div < sqrt(x) +1; div++)
    {
        if (x%div == 0){
            return 0;
        }
    }
    return 1;
    
}

int main(int argc, char const *argv[])
{
    int *integers  = NULL, *result = NULL;
    int n, rc;

    srand(42);


    if (argc !=2){
        printf("Error:\n\tfunctional <number of pairs>\n");
        exit(EXIT_FAILURE);

    }

    n = atoi(argv[1]);

    integers = malloc(sizeof(int) * n);

    if (integers == NULL){
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        integers[i] = rand();
    }

    

    result = filter(integers, n, &even, &rc);

    printf("Even numbers:\n");

    for (int i = 0; i < rc; i++)
    {
        printf("\t%d\n", result[i]);
    }
    printf("\n");

    result = filter(integers, n, &odd, &rc);

    printf("Odd numbers:\n");
    for (int i = 0; i < rc; i++)
    {
        printf("\t%d\n", result[i]);
    }
    printf("\n");

    result = filter(integers, n, &is_prime, &rc);

    printf("Prime numbers:\n");
    for (int i = 0; i < rc; i++)
    {
        printf("\t%d\n", result[i]);
    }
    printf("\n");


    return 0;
}
