#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
int data;
struct Node*next;
}Node;


Node* initial(){
Node*head=(Node*)malloc(sizeof(Node));
if(head==NULL){
exit(0);
}
head->data=10086;
head->next=NULL;
return head;
}

int getlength(Node *head){
Node*tmp=head->next;
int i=1;
while(tmp!=NULL){
tmp=tmp->next;
i+=1;
}
return i;
}

void headinsert(Node*head,int data){
Node*newnode=(Node*)malloc(sizeof(Node));
if(newnode==NULL){
return;
}
newnode->data=data;
newnode->next=head->next;
head->next=newnode;
}

void tailinsert(Node*head,int data){
Node*newnode=(Node*)malloc(sizeof(Node));
if(newnode==NULL){
return;
}
newnode->data=data;
newnode->next=NULL;

Node*tmp=head;
while(tmp->next!=NULL){
tmp=tmp->next;
}
tmp->next=newnode;
}

void ptf(Node*head){
Node* tmp=head->next;
int i=1;
while(tmp!=NULL){
printf("elem[%d]:%d\n",i,tmp->data);
tmp=tmp->next;
i++;
}
}

int main(){
Node*head=initial();
headinsert(head,1);
headinsert(head,2);
tailinsert(head,10086);
ptf(head);


return 0;
}

