#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int elemtype;
typedef struct Node
{
	struct Node*next;
	elemtype data;
}Node;

Node*inithead(){
	Node*head=(Node*)malloc(sizeof(Node));
	if (head==NULL)
	{
		return NULL;
	}
	head->next=NULL;
	head->data=10086;
	return head;
}

int getlength(Node*head){
	if (head->next==NULL)
	{
		return 0;
	}
	Node*tmp=head->next;
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
	if (length==0)
	{
		printf("lk is empty\n");
		return;
	}
	Node*tmp=head->next;
	int i=1;
	while (tmp!=NULL)
	{
		printf("elem[%d]:%d\n",i,tmp->data);
		tmp=tmp->next;
		i+=1;
	}

	printf("--------------------\n");
}

void headinsert(Node*head,elemtype elem){
	Node*newnode=(Node*)malloc(sizeof(Node));
	if (newnode==NULL)
	{
		return;
	}
	newnode->next=head->next;
	head->next=newnode;
	newnode->data=elem;
}

void tailinsert(Node*head,elemtype elem){
	Node*newnode=(Node*)malloc(sizeof(Node));
	if (newnode==NULL)
	{
		return;
	}
	Node*tmp=head->next;
	if (tmp==NULL)
	{
		headinsert(head,elem);
		return;
	}
	while(tmp!=NULL)
	{
		if (tmp->next==NULL)
		{
			newnode->data=elem;
			newnode->next=NULL;
			tmp->next=newnode;
			break;
		}
		tmp=tmp->next;
	}

}

void insert(Node*head,elemtype elem,int index){
	Node*newnode=(Node*)malloc(sizeof(Node));
	int length=getlength(head);
	if (index==0||index>length)
	{
		return;
	}
	int i=1;
	Node*tmp=head->next;
	while (i<index-1)
	{
		i+=1;
		tmp=tmp->next;		
	}
	newnode->data=elem;
	newnode->next=tmp->next;
	tmp->next=newnode;
}

elemtype indexsearch(Node*head,int index){
	// Node*head=(Node*)malloc(sizeof(Node));
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
	if (index<0||index>length)
	{
		printf("index out of range!\n");
		return;
	}
	int i=1;
	Node*tmp=head->next;
	while (i<index-1)
	{
		i+=1;
		tmp=tmp->next;
	}
	tmp->next=tmp->next->next;
}

void valuedelete(Node*head,elemtype elem){
	int index = valuesearch(head,elem);
	indexdelete(head,index);
}

void indexchage(Node*head,int index,elemtype elem){
	int i=1;
	Node*tmp=head->next;
	while (i<index)
	{
		tmp=tmp->next;
		i+=1;
	}
	tmp->data=elem;

}

void valuechange(Node*head,elemtype source,elemtype target){
	int index=valuesearch(head,source);
	indexchage(head,index,target);
}



int main(int argc, char const *argv[])
{
	Node*head=inithead();
	headinsert(head,3);
	headinsert(head,2);
	headinsert(head,1);
	tailinsert(head,4);
	tailinsert(head,56);
	insert(head,33,3);
	insert(head,44,4);
	insert(head,55,5);
	ptf(head);
	indexdelete(head,3);
	indexdelete(head,7);
	valuedelete(head,4);
	ptf(head);
	indexchage(head,1,10086);
	indexchage(head,2,10010);
	valuechange(head,44,88);
	ptf(head);



	free(head);
	return 0;
}
