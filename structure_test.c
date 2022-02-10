#include <stdio.h>

#define NUMOFSUB 3

struct Scores{
    int math;
    int engl;
    int kor;
};

struct Student{
    char name[20];
    int age; 
    int grade;
    struct Scores score;
};

int main(){
    struct Student s1;
    printf("[학생] \n");
    printf("이름: ");
    scanf("%s", s1.name);
    printf("나이: ");
    scanf("%d", &s1.age);
    printf("학년: ");
    scanf("%d", &s1.grade);

    printf("수학: ");
    scanf("%d", &s1.score.math);
    printf("영어: ");
    scanf("%d", &s1.score.engl);
    printf("국어: ");
    scanf("%d", &s1.score.kor);

    int avg = ( s1.score.math + s1.score.engl + s1.score.kor ) 
                / NUMOFSUB;
    printf("평균 점수: %d", avg);

    return 0;
}