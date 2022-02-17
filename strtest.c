#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(void){
    char str1[50];
    char str2[50];

    printf("문자열 2줄을 입력하세요.\n");
    // fgets(str1, 50, stdin);
    // fgets(str2, 50, stdin);

    scanf("%[^\n]s", str1); 
	getchar();
    scanf("%[^\n]s", str2); 

    // for the test    
    // printf("1%s", str1);
    // printf("2%s", str2);
    

    int cmp = strlen(str1)- strlen(str2);

    // switch(cmp){
    //     case -1:
    //     printf("%d", strlen(str2));
    //     break;

    //     case 0:
    //     strcat(str1, str2);
    //     printf("%s", str1);
    //     break;

    //     case 1:
    //     printf("%d", strlen(str1));
    // }

    if(cmp == 0){
        strcat(str1, str2);
        printf("%s", str1);
    }else if (cmp < 0){
        printf("%d", strlen(str2));
    }else if (cmp > 0){
        printf("%d", strlen(str1));
    }


    return 0;
}