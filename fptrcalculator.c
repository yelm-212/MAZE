#include <stdio.h>

int sum(int x, int y){
    return x + y;
}
int sub(int x, int y){
    return x - y;
}
int mult(int x, int y){
    return x * y;
}
int div(int x, int y){
    return x / y;
}

int main(void){
    int a,b;
    char op;

    int (*fptr[4])(int, int)= { sum, sub, mult, div};


    printf("a :");
    scanf("%d", &a);

    printf("b :");
    scanf("%d", &b);

    getchar();
    printf("연산 종류 (+,-,*,/) :");
    scanf("%c", &op);

    switch (op)
    {
    case '+':
    printf("a + b = %d", op, fptr[0](a, b));
        break;
    case '-':
    printf("a - b = %d", op, fptr[1](a, b));
        break;
    case '*':
    printf("a * b = %d", op, fptr[2](a, b));
        break;
    case '/':
    printf("a / b = %d", op, fptr[3](a, b));
        break;
    
    default:
        printf("Wrong operator...");
        break;
    }

// printf("a %c b = %d", op, fptr(a, b));

    return 0;
}