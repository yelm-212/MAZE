#include <stdio.h>
#include <stdlib.h>


// if input case is not prime number(false), then this returns 1
// if input case is prime number(true), then this returns 0
int primechecker(int n){
    int i, flag = 0 ;

    if (n==0 || n == 1)
        flag =1;

    for (i = 2; i<=n/2; ++i){
        // if n is divisivle by i,
        // then n is not prime number.
        // change flag to 1 for none prime number.
        if (n % i==0){
            flag = 1;
            return flag;
        }

    }

    return flag;
}

int main(void){
    int cnt;
    int * num;
    int cntprime = 0;

    printf("숫자의 개수:");
    scanf("%d", &cnt);

    num = (int*)malloc(sizeof(int)*cnt);

    for(int i=1; i<=cnt;i++){
        scanf("%d", &num[i]);
        
        if (primechecker(num[i]) == 0)
            cntprime++;
        
        
    }
    free(num);

    printf("\n소수의 개수는 %d 입니다.", cntprime);

    return 0;
}