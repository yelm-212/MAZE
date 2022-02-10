#include <stdio.h>

void findMax(int **pMax, int* array, int size);

int main(){
    int array[5];

    // 입력받은 값을 배열에 저장하는 반복문
    for(int i=0;i<5;i++){
    scanf("%d", &array[i]);
    }

    int* max = 0;

    findMax(&max, array, sizeof(array)/sizeof(int));

    printf("최대값: %d\n", *max);
    return 0;
}

void findMax(int **pMax, int* array, int size){
    int * max = &array[0];

    for(int i=0; i<size; i++){
        if (*max <=array[i])
            max = &array[i];
    }
    * pMax = max;

}
