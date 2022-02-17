#include "calc.h"

int main(){
    int a,b;
    char op;

    // int (*fptr[4])(int, int)= { sum, sub, mult, div};


    printf("a :");
    scanf("%d", &a);

    printf("b :");
    scanf("%d", &b);

    getchar();

    printf("a - b = %d\n", sub(a, b));
    printf("a + b = %d\n", sum(a, b));
    printf("a * b = %d\n", mult(a, b));
    printf("a / b = %d\n", div(a, b));

    return 0;
}