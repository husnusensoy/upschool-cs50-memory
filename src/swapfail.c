#include<stdio.h>

void swap(int x,int y){
    int temp;

    printf("\nPostal code/address of x (assigned to be a)=%d is %p\n", x, &x);
    temp = y;
    y = x;
    x = temp;

    printf("Before swap call\n\tx: %d\n\ty: %d\n", x, y);

}

int main(int argc, char const *argv[])
{
    int a=3, b=5;

    printf("\nPostal code/address of a=%d is %p\n", a, &a);

    printf("Before swap call\n\ta: %d\n\tb: %d\n", a, b);

    swap(a,b);

    printf("Before swap call\n\ta: %d\n\tb: %d\n", a, b);


    return 0;
}
