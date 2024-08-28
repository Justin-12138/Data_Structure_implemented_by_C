#include<stdio.h>
#include<stdlib.h>

void  merge(int *arr1,int size1,int *arr2,int size2){
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
    for (int i = 0; i < size3; i++)
    {
        printf("elem[%d]:%d\n",i+1,arr3[i]);
    }
}




int main(){
    int arr1[]={11,2,3};
    int arr2[]={44,6,11,2};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    merge(arr1,size1,arr2,size2);



    // 不能：int arr3[size3]={};
    // 可以：int arr3[size2];
    int arr[3]={1,2,3};
    printf("arr's addr:%p\n",&arr);

    for (int i = 0; i < 3; i++)
    {
        printf("arr's elem [%d] addr:%p\n",i+1,&arr[i]);   
    }
    printf("------------------------------------------------\n");

    int *data=(int *)malloc(sizeof(int)*3);
    printf("ptr's addr:%p\n",data);
    for (int i = 0; i < 3; i++)
    {
        data[i]=i*2;
    }

    int j=0;
    while (j<3)
    {
        printf("ptr's:elem of data[%d]:%d\n",j+1,data[j]);
        j++;
    }
    for (int i = 0; i < 3; i++)
    {
        printf("ptr's elem [%d] addr:%p\n",i+1,&data[i]);   
    }

    free(data);
    data = NULL;


    return 0;
}

