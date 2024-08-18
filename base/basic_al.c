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



int main(){
	int arr[]={4,3,2,1};
	int n = (sizeof(arr)/sizeof(arr[0]));
	int i,j,key;
	

	for (int i = 0; i < n; i++)
	{
		printf("%d\n",arr[i]);
	}
	
	

	return 0;
}