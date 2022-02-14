#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(void){
    int cnt;
    int * point;
    int sum=0; 
    float avg =0;

    printf("학생의 수:");
    scanf("%d", &cnt);

    point = (int*)malloc(sizeof(int)*cnt);

    for(int i=1; i<=cnt;i++){
        printf("학생 %d: ", i);
        scanf("%d", &point[i]);
        sum += point[i];
    }
    free(point);

    avg = sum / cnt;
    printf("\n평균: %.2f", avg);

    return 0;
}