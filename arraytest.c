#include <stdio.h>

int main(){

   int intarray[4][4];
   for (int i=0;i<4;i++){
       for(int j=0;j<4;j++){
           scanf("%d", &intarray[i][j]);
       }
   }

   printf("[변경 전]\n");
   for (int i=0;i<4;i++){
       for(int j=0;j<4;j++){
           printf("%d ", intarray[i][j]);
       }
       printf("\n");
   }

   printf("[변경 후]\n");
   for (int i=0;i<4;i++){
       for(int j=0;j<4;j++){
           printf("%d ", intarray[j][i]);
       }
       printf("\n");
   }


    return 0;
}