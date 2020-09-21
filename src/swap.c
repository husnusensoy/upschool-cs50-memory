#include<stdio.h>
#include<stdlib.h>

void swap(int *x_ptr, int *y_ptr){

    int temp;

    printf("\nPostal code/address of x (assigned to be a)=%d is %p\n", *x_ptr, x_ptr);


    temp = *y_ptr;
    *y_ptr = *x_ptr;
    *x_ptr = temp;

    printf("Before swap call\n\tx: %d\n\ty: %d\n", *x_ptr,*y_ptr);

}

int main(int argc, char const *argv[])
{
    int a, b;

    if (argc != 3){
        printf("Missing arguments\n");
        exit(EXIT_FAILURE);
    }

    printf("Name of the program: %s\n", argv[0]);

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    printf("\nPostal code/address of a=%d is %p\n", a, &a);

    printf("Before swap call\n\ta: %d\n\tb: %d\n", a, b);

    swap(&a, &b);

    printf("Before swap call\n\ta: %d\n\tb: %d\n", a, b);


    return 0;
}
