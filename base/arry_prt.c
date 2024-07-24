#include<stdio.h>
#include<stdlib.h>



int main(){
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

