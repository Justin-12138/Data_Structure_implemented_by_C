#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define numstu 5

typedef struct Stu{
    int id;
    double grade;
    char name[20];
}Stu;


int main(){
    Stu students[numstu]={
        {1,77,"ALex"},
        {2,88,"julie"},
        {3,90.6,"Black"},
        {4,99.55,"jiojio"},
        {5,99.55,"justin"}
};
    double maxgrade=students[0].grade;
    for (int i = 0; i < numstu; i++)
    {
        if (students[i].grade>=maxgrade)
        {
            maxgrade=students[i].grade;
        }        
    }

    printf("max grade:%.2f\n",maxgrade);
    for (int i = 0; i < numstu; i++)
    {
        if (students[i].grade==maxgrade)
        {
            printf("id:%d,name:%s,grade:%.2f\n",students[i].id,students[i].name,students[i].grade);
        }   
    }
    return 0;
}