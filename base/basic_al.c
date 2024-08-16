#include<stdio.h>
#include<stdlib.h>




int main(){
	int arr[]={4,23,2,10};
	int length = (sizeof(arr)/sizeof(arr[0]));
	printf("%d\n",length);
	printf("%ld\n",sizeof(arr));
	// buble rank
	for (int j = 0; j < length-1; j++)
	{
		for (int i = 0; i < length-1; i++)
	{
		if (arr[i]>arr[i+1])
		{
			int swap;
			swap=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=swap;
		}
	}
	}
	


	for (int i = 0; i < length; i++)
	{
		printf("elem:%d\n",arr[i]);
	}
	
	





	return 0;
}