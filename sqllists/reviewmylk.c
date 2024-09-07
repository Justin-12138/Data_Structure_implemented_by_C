#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int elemtype;
typedef struct Node
{
	struct Node*next;
	elemtype data;
}Node;


Node* inittial(){
	Node*head=(Node*)malloc(sizeof(Node));
	if (head==NULL)
	{
		return NULL;
	}
	head->data=10086;
	head->next=NULL;
}

int getlength(Node*head){
	Node*tmp=head->next;
	if (tmp==NULL)
	{
		return 0;
	}
	int i=0;
	while (tmp!=NULL)
	{
		tmp=tmp->next;
		i+=1;
	}
	return i;
}

void ptf(Node*head){
	int length=getlength(head);
	printf("length of lk:%d\n",length);
	Node*tmp=head->next;
	if (tmp==NULL)
	{
		printf("lk is empty!\n");
		return;
	}
	int i=0;
	while (tmp!=NULL)
	{
		i+=1;
		printf("elem[%d]:%d\n",i,tmp->data);
		tmp=tmp->next;
	}
	printf("----------------------\n");
}

void headinsert(Node*head,elemtype elem){
	Node*newnode=(Node*)malloc(sizeof(Node));
	newnode->data=elem;
	newnode->next=head->next;
	head->next=newnode;
}

void tailinsert(Node*head,elemtype elem){
	Node*newnode=(Node*)malloc(sizeof(Node));
	Node*tmp=head;
	if (tmp->next==NULL)
	{
		return;
	}
	while (tmp->next!=NULL)
	{
		tmp=tmp->next;	
	}
	newnode->next=NULL;
	newnode->data=elem;
	tmp->next=newnode;
}

void insert(Node*head,elemtype elem,int index){
	int length=getlength(head);
	if (index<0||index>length+1)
	{
		printf("inde out of range!");
		return;
	}
	Node*newnode=(Node*)malloc(sizeof(Node));
	int i=1;
	Node*tmp=head->next;
	
	if (index==1)
	{
		headinsert(head,elem);
		return;
	}
	else if (index==length+1)
	{
		tailinsert(head,elem);
		return;
	}
	while (i<index-1)
	{
		i+=1;
		tmp=tmp->next;
	}
	newnode->next=tmp->next;
	newnode->data=elem;
	tmp->next=newnode;
}

elemtype indexsearch(Node*head,int index){
	Node*tmp=head->next;
	int i=1;
	while (i<index)
	{
		tmp=tmp->next;
		i+=1;
	}
	return tmp->data;
}

int valuesearch(Node*head,elemtype elem){
	int length=getlength(head);
	Node*tmp=head->next;
	for (int i = 1; i < length+1; i++)
	{
		if (tmp->data==elem)
		{
			return i;
		}
		tmp=tmp->next;
	}
}

void indexdelete(Node*head,int index){
	int length=getlength(head);
	if (index<=0||index>length+1)
	{
		printf("index out of range!\n");
		return;
	}
	else if (length<=0)
	{
		printf("lk is empty!\n");
		return;
	}
	int i=0;
	Node*tmp=head;
	while (i<index-1)
	{
		tmp=tmp->next;
		i+=1;
	}
	tmp->next=tmp->next->next;
}

void valuedelete(Node*head,elemtype elem){
	int index=valuesearch(head,elem);
	indexdelete(head,index);
}

void indexchange(Node*head,int index,elemtype elem){
	int length=getlength(head);
	Node*tmp=head->next;
	int i=1;
	while (i<index)
	{
		tmp=tmp->next;
		i+=1;
	}
	tmp->data=elem;
}

void valuechage(Node*head,elemtype source,elemtype target){
	int length=getlength(head);
	if (length<=0)
	{
		printf("lk is empty!\n");
		return;
	}
	int index=valuesearch(head,source);
	indexchange(head,index,target);
}

void main(){
	Node*head=inittial();
	headinsert(head,11);
	headinsert(head,22);
	tailinsert(head,33);
	insert(head,99,2);
	insert(head,111,1);
	insert(head,999,5);
	ptf(head);

	indexdelete(head,5);
	valuedelete(head,111);
	ptf(head);

	int index = valuesearch(head,22);
	elemtype elem = indexsearch(head,1);
	printf("elem:%d 's index is:%d\n",elem,index);
	ptf(head);

	indexchange(head,1,10086);
	indexchange(head,2,10010);
	valuechage(head,11,10001);


	ptf(head);
	free(head);
	return;
}