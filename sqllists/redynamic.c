#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct{
	ElemType*data;
	int length;
	int capacity;
}dysql;

void init_dysql(dysql*d,int init_capacity){
	d->data=(ElemType*)malloc(sizeof(ElemType)*init_capacity);
	if(d->data==NULL){
		printf("Memory allocation failed!\n");
		return;
	}
	d->length=0;
	d->capacity=init_capacity;
}


void extend(dysql*d){
	int newcapacity=(d->capacity) * 2;
	ElemType*newdata=(ElemType*)realloc(d->data,sizeof(ElemType) * newcapacity);
	if(newdata==NULL){
		printf("Extension memory failed!\n");
		return ;
	}
	d->data=newdata;
	d->capacity=newcapacity;
}

void insert_head(dysql*d,ElemType elem){
	if(d->length > d->capacity){
		extend(d);
	}
	for(int i=d->length;i>0;i--){
		d->data[i]=d->data[i-1];
	}
	d->data[0]=elem;
	d->length++;
}

void insert_tail(dysql*d,ElemType elem){
	if(d->length >= d->capacity){
		extend(d);
	}
	d->data[d->length]=elem;
	d->length++;
}


void insert_index(dysql*d,int index,ElemType target){
	if(d->length>=d->capacity){
		extend(d);
	}
	if(index<1||index>d->length+1){
		printf("index out of range!");
		return;
	}
	for(int i=d->length;i>index-1;i--){
		d->data[i]=d->data[i-1];
	}
	d->data[index-1]=target;
	d->length++;
}


void del_index(dysql*d,int index){
	if(index<1||index>d->length+1){
		printf("index out of range!s\n");
		return;
	}
	for(int i=index-1;i<d->length;i++){
		d->data[i]=d->data[i+1];	
	}
	d->length--;
}


ElemType search_index(dysql*d,int index){
	if(index>d->length||index<1){
		printf("index out of range!");
		return 0;
	}
	return d->data[index-1];
}


int search_value(dysql*d,ElemType elem){
	for(int i=0;i<d->length;i++){
		if(d->data[i]==elem){
		return i+1;
		}
	}
}

void change(dysql*d,ElemType target,ElemType source){
	int index = search_value(d,source);
	d->data[index-1]=target;
}



void ptf(dysql*d){
	for(int i=0;i<d->length;i++){
		printf("elem[%d]:%d\n",i+1,d->data[i]);
	}
	printf("length:%d\n",d->length);
	printf("capacity:%d\n",d->capacity);
}




void del_dysql(dysql*d){
	free(d->data);
	d->data=NULL;
	d->length=0;
	d->capacity=0;
}



int main(){


	dysql d1;
	init_dysql(&d1,3);
	insert_tail(&d1,1);
	insert_tail(&d1,2);
	insert_tail(&d1,3);
	insert_tail(&d1,4);
	insert_index(&d1,3,10010);
	
	printf("---------------------------------\n");
	ptf(&d1);
	printf("---------------------------------\n");
	
	
	del_index(&d1,4);
	
	printf("---------------------------------\n");
	ptf(&d1);
	printf("---------------------------------\n");
	
	change(&d1,10086,4);
	
	


	ptf(&d1);
	del_dysql(&d1);


return 0;}



