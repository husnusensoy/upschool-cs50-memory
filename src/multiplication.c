#include <stdio.h>


int multplication(int a, int b){

    printf("\nPostal code/address of a=%d is %p\n", a, &a);
    return a * b;
}

int main(int argc, char const *argv[])
{
    int x = 5, y = 3, z;

    printf("\nPostal code/address of x=%d is %p\n", x, &x);
    printf("Memory address of y=%d is %p\n", y, &y);

    printf("Pointee of %p address of x=%d\n", &x, *(&x) );

    z = multplication(x,y);

    printf("%d x %d = %d\n",x,y,z);


    return 0;
}
