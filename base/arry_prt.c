#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void ptf(int *arr,int size){
    for (int i = 0; i < size; i++)
    {
        printf("elem[%d]:%d\n",i+1,arr[i]);
    }
    printf("-----------------------------\n");
}

int *merge(int *arr1,int size1,int *arr2,int size2){
    int size3=size1+size2;
    int *arr3=(int*)malloc(sizeof(int)*size3);
    for (int i = 0; i < size3; i++)
    {
        if (i<size1)
        {
            arr3[i]=arr1[i];
        }
        else{
            arr3[i]=arr2[i-size1];
        }
    }
    return arr3;
}


int  *desrank(int *arr,int size){
    for (int i = 0; i < size-1; i++)
    {
        int swap;
        for (int j = 0; j < size-1-i; j++)
        {
            swap=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=swap;
        }
    }
    return arr;
}


int *bublerank(int *arr,int size,bool ascend){
for (int i = 0; i < size-1; i++)
{
    for (int j = 0; j < size -1; j++)
    {
        int swap;
        if (ascend)
        {
            if (arr[j]>arr[j+1])
            {
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
        else{
            if (arr[j]<arr[j+1])
            {
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;

            }
        }
        
    }
    
}

return arr;

}

int main(){
    int arr1[]={11,2,3};
    int arr2[]={44,6,6,2};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    int *arr3=merge(arr1,size1,arr2,size2);
    ptf(arr3,7);
    int *arr4=desrank(arr3,7);
    ptf(arr4,7);

    int *arr5=bublerank(arr3,7,false);
    ptf(arr5,7);


    // 不能：int arr3[size3]={};
    // 可以：int arr3[size2];
    // int arr[3]={1,2,3};
    // printf("arr's addr:%p\n",&arr);

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("arr's elem [%d] addr:%p\n",i+1,&arr[i]);   
    // }
    // printf("------------------------------------------------\n");

    // int *data=(int *)malloc(sizeof(int)*3);
    // printf("ptr's addr:%p\n",data);
    // for (int i = 0; i < 3; i++)
    // {
    //     data[i]=i*2;
    // }

    // int j=0;
    // while (j<3)
    // {
    //     printf("ptr's:elem of data[%d]:%d\n",j+1,data[j]);
    //     j++;
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("ptr's elem [%d] addr:%p\n",i+1,&data[i]);   
    // }

    // free(data);
    // data = NULL;


    return 0;
}

