#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int main(){
    int arr[3][3]={
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    for (int i = 0; i < 3; i++)
    {
        printf("the first row:%d\n",arr[0][i]);
    }
    

}
