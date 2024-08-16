#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


void bubblerank(int arr[],int n,bool ascend){
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			int swap;
			if (ascend==true)
			{
				if (arr[j]>arr[j+1])
				{
					
					swap = arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=swap;
				}
			}
			else if (ascend==false)
			{
				if (arr[j]<arr[j+1])
				{

					swap=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=swap;		
				}	
			}	
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("elem:%d,",arr[i]);
	}
}

void insertrank(int arr,int n,bool ascend){
	//[5,4,3,2,1]
	/*
	5,4
	
	*/


}

int main(){
	int arr[]={4,23,2,10};
	int n = (sizeof(arr)/sizeof(arr[0]));
	printf("%d\n",n);
	printf("%ld\n",sizeof(arr));
	bubblerank(arr,n,true);
	printf("\n");
	bubblerank(arr,n,false);
	//[5,4,3,2,1]
	for (int i = 1; i < n; i++)
	{
		int temp=arr[i];
		if (arr[i>temp])
		{
			
		}
		

		for (int j = 0; i < n; j++)
		{
			/* code */
		}
		
	}
	
	

	
	
	





	return 0;
}