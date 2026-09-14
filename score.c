#include<stdio.h>

int main(){
    int score;
    printf("Type your score right here:\n");
    scanf("%d",&score);
    if(score>90)
    {
        printf("Excellent!");
    }
    else if(score>60)
    {
        printf("Not bad!");
    }
    else
    {
        printf("Awful!");
    }
}