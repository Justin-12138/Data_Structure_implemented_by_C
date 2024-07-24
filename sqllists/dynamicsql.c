#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct {
	ElemType *data;
	int length;
	int capacity;
}dyarr;

void init_dyarr(dyarr*d,int init_capacity){
	d->data=(ElemType*)malloc(sizeof(ElemType)*init_capacity);
	if(d->data==NULL){
		printf("Memory allocation failed!Check Memory free spaces\n");
		return;
	}
	d->length=0;
	d->capacity=init_capacity;
}

void extension(dyarr*d){
	int newcapacity = d->capacity * 2;
	ElemType *newdata = (ElemType*)realloc(d->data,sizeof(ElemType) * newcapacity);
	if(newdata==NULL){
		printf("Extend failed!\n");
		return;
	}
	d->data=newdata;
	d->capacity=newcapacity;

}

void insert_end(dyarr*d,ElemType elem){
	if(d->length>d->capacity){
		extension(d);
	}
	d->data[d->length]=elem;
	d->length++;
}

void insert_head(dyarr*d,ElemType elem){
	if(d->length>d->capacity){
		extension(d);
	}
	for(int i=d->length;i>0;i--){
		d->data[i]=d->data[i-1];
	}
	d->data[0]=elem;
	d->length++;

}

void insert_index(dyarr*d,int index,ElemType elem){
	if(index>d->length+1||index<1){
		printf("illegal index!");
		return;
	}
	if(d->length>=d->capacity){
		extension(d);
	}

	for(int i = d->length;i>index-1;i--){
		d->data[i]=d->data[i-1];
	}
	d->data[index-1]=elem;
	d->length++;
}

void del_index(dyarr*d,int index){
	if(index<1||index>d->length){
		printf("Index out of range!\n");
		return;
	}
	for(int i=index-1;i<d->length-1;i++){
		d->data[i]=d->data[i+1];
	}
	d->length--;
}

void del_value(dyarr*d,ElemType elem){
	for(int i=0;i<d->length;i++){
		if(d->data[i]==elem){
			del_index(d,i+1);
			return;
		}
	}
}

ElemType search_byindex(dyarr*d,int index){
	if(index<1||index>d->length){
	return 0;}
	return d->data[index-1];
	
}
int search_byvalue(dyarr*d,ElemType elem){
	for(int i=0;i<d->length;i++){
		if(d->data[i]==elem){
			return i+1;
		}
	}
}

void change_byindex(dyarr*d,int index,ElemType elem){
	d->data[index-1]=elem;
}

void change_byvalue(dyarr*d,ElemType target,ElemType source){
	int index = search_byvalue(d,source);
	change_byindex(d,index,target);

}


void ptf(dyarr*d){
	int i=0;
	while(i<d->length){
		printf("elem of dynamic sql[%d]:%d\n",i+1,d->data[i]);
		i++;
	}

}

void del(dyarr *d){
	free(d->data);
	d->data=NULL;
	d->length=0;
	d->capacity==0;
}



int main(){
	dyarr d1;
	init_dyarr(&d1,10);
	insert_end(&d1,1);
	insert_end(&d1,2);
	insert_end(&d1,3);
	insert_end(&d1,100);
	insert_index(&d1,1,1000);
	insert_head(&d1,0);

	ptf(&d1);
	printf("---------------del before------------------\n");

	del_value(&d1,100);
	del_index(&d1,1);
	ptf(&d1);
	printf("---------------cahnge before------------------\n");
	change_byindex(&d1,1,10086);
	change_byvalue(&d1,200,2);
	
	
	
	
	ptf(&d1);
	del(&d1);
	return 0;
}
