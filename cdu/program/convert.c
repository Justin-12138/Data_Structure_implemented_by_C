#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

double s2k(double ssd){
    return ssd+273.15;
}

double s2h(double ssd){
    return ssd*1.8+32;
}

void main(){
    printf("25摄氏度->开尔文:%.2f\n",s2k(25));
    printf("25摄氏度->华氏度:%.2f\n",s2h(25));
    int num;
    scanf("%d",&num);    
    printf("num:%d\n",num);
    return;

}