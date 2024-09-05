#include<stdio.h>


int findmin(int a,int b){
    return (a < b) ? a : b;
}

void swap(int *a,int *b){
    int swap;
    swap=*a;
    *a=*b;
    *b=swap;

}

void ptf(int arr[],int length){
    for (int i = 0; i < length; i++)
    {
        printf("elem[%d]:%d\n",i+1,arr[i]);
    }
    printf("---------------------\n");
}


int main(){
    int arr[7]={66,3,7,12,1,17,6};
    

    for (int i = 7/2-1; i > -1; i--)
    {
        if (i==0)
        {
            int min=findmin(arr[1],arr[2]);
            if (min==arr[1])
            {
                swap(&arr[0],&arr[1]);
            }
            else if (min==arr[2])
            {
                swap(&arr[0],&arr[2]);
            }
        }
        else
        {
            int min=findmin(arr[2*i+2],arr[2*i+1]);
            if (arr[2*i+2]==min)
            {
                swap(&arr[2*i+2],&arr[i]);
            }
            else if (arr[2*i+1]==min)
            {
                swap(&arr[2*i+1],&arr[i]);
            }

        }
    }


    ptf(arr,7);






    return 0;
}