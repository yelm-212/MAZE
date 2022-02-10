#include <stdio.h>

#define ROW 3
#define COL 3

void multiplyMatrix(int A[][COL], int B[][COL], int res[][COL]){

    // initialize res elements to 0
    for (int i=0;i<ROW;i++){
       for(int j=0;j<COL;j++){
           res[i][j] = 0;
       }
   }
    

    // A와 B행렬의 곱을 res에 저장한다.
    for (int i=0;i<ROW;i++){
       for(int j=0;j<COL;j++){
           for (int k=0; k<COL; k++){
                res[i][j] += A[i][k] * B[k][j];
           }
       }
    }

    // print res elements
    for (int i=0;i<ROW;i++){
       for(int j=0;j<COL;j++){
           printf("%d ", res[i][j]);
       }
       printf("\n");
   }

}

void arrayInput(int arr[][COL]){

    // initialize arr elements to 0
    for (int i=0;i<ROW;i++){
       for(int j=0;j<COL;j++){
            arr[i][j] = 0;
       }
   }

    for (int i=0;i<ROW;i++){
       for(int j=0;j<COL;j++){
           scanf("%d", &arr[i][j]);
       }
   }

}

int main(void){

   int arr1[ROW][COL];
   int arr2[ROW][COL];

//   int (*ptr1)[COL] = arr1;
//   int (*ptr2)[COL] = arr2;

    printf("[행렬 A]\n");

//     for (int i=0;i<ROW;i++){
//        for(int j=0;j<COL;j++){
//            scanf("%d", &arr1[i][j]);
//        }
//    }
//  해당 부분을 별도 함수(arrayInput)로 분리해 수정하였음\

    arrayInput(arr1);

    printf("[행렬 B]\n");

    arrayInput(arr2);

//     for (int i=0;i<ROW;i++){
//        for(int j=0;j<COL;j++){
//            scanf("%d", &arr2[i][j]);
//        }
//    }

    
    printf("[행렬 곱]\n");

    int result[ROW][COL];

    multiplyMatrix(arr1, arr2, result);
    
//  changed to function multiplyMatrix().    
    // for (int i=0;i<ROW;i++){
    //    for(int j=0;j<COL;j++){
    //        for (int k=0; k<COL; k++){
    //             result[i][j] += arr1[i][k] * arr2[k][j];
    //        }
    //    }
    // }

//     for (int i=0;i<ROW;i++){
//        for(int j=0;j<COL;j++){
//            printf("%d ", result[i][j]);
//        }
//        printf("\n");
//    }


    return 0;
}