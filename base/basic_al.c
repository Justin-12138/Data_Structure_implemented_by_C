#include<stdio.h>


int main(){
	int arry[5]={2,3,4,1,77};

	//find max,min
	int data_max=arry[0];
	int data_min=arry[0];
	for (int i = 1; i < 5; i++)
	{
		if (arry[i]>=data_max)
		{
			data_max=arry[i];
		}
	}
	printf("maxnum:%d\n",data_max);
	
	for (int i = 1; i < 5; i++)
	{
		if (arry[i]<=data_min)
		{
			data_min=arry[i];
		}
	}
	printf("maxnum:%d\n",data_min);

	//swap
	int temp;
	temp=arry[2];
	arry[2]=arry[3];
	arry[3]=temp;
	int j=0;
	while (j<5)
	{
		printf("elem of arry:%d\n",arry[j]);
		j++;
	}
	
	return 0;
}