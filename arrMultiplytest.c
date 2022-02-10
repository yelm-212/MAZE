#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

int main(void){

   int arr1[ROW][COL];
   int arr2[ROW][COL];

   //int (*ptr1)[COL] = arr1;
   //int (*ptr2)[COL] = arr2;

    printf("[행렬 A]\n");

    for (int i=0;i<ROW;i++){
       for(int j=0;j<COL;j++){
           scanf("%d", &arr1[i][j]);
       }
   }
    printf("[행렬 B]\n");

    for (int i=0;i<ROW;i++){
       for(int j=0;j<COL;j++){
           scanf("%d", &arr2[i][j]);
       }
   }
    printf("[행렬 곱]\n");

    //multiplyMatrix();

    int result[ROW][COL];

    for (int i=0;i<ROW;i++){
       for(int j=0;j<COL;j++){
           result[i][j] = 0;
       }
   }
    
    for (int i=0;i<ROW;i++){
       for(int j=0;j<COL;j++){
           for (int k=0; k<COL; ++k){
                result[i][j] += arr1[i][k] * arr2[k][j];
           }
       }
    }

    for (int i=0;i<ROW;i++){
       for(int j=0;j<COL;j++){
           printf("%d ", result[i][j]);
       }
       printf("\n");
   }




    return 0;
}