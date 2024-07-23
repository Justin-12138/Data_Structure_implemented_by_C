#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct {
	ElemType *data;
	int length;
	int capacity;
}dyarr;


void init_dyarr(dyarr*d,int init_size){
	d->data=(ELem*)malloc(sizeof(ElemType)*ini_size);
	d->length=0;
	d->capacity=init_size;
}



int main(){




	return 0;
}
