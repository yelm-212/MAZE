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
    int res;

    int (*fptr)(int, int);

    printf("a :");
    scanf("%d", &a);

    printf("\nb :");
    scanf("%d", &b);

    printf("\n연산 종류 (+,-,*,/) :");
    scanf("%c", &op);

    switch (op)
    {
    case '+':
        fptr = sum;
        break;
    case '-':
        fptr = sub;
        break;
    case '*':
        fptr = mult;
        break;
    case '/':
        fptr = div;
        break;
    
    default:
        printf("Wrong operator...");
        break;
    }

    printf("\na %c b = %d", op, res);

    return 0;
}