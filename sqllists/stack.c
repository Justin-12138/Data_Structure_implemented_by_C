#include<stdio.h>
#include<stdlib.h>

#define maxsize 5
typedef struct stack{
int data[maxsize];
int top;
}stack;

void initstack(stack*s){
s->top=-1;
}

void isempty(stack*s){
if(s->top==-1){
printf("the stack is empty!\n");
return;
}
}

void isfull(stack*s){
if(s->top==maxsize-1){
printf("the stack is full!\n");
return;
}
else if(s->top>-1&&s->top<maxsize-1){
printf("the stack is not full!\n");
return;
}
}

void push(stack*s,int data){
isfull(s);
s->data[++s->top]=data;
}

int pop(stack*s){
isempty(s);
int x=s->data[s->top--];
return x;
} 


int main(){
stack s1;
initstack(&s1);
isempty(&s1);
push(&s1,5);
push(&s1,4);
push(&s1,3);
push(&s1,2);
push(&s1,1);
isfull(&s1);
printf("top elem:%d\n",pop(&s1));
isfull(&s1);



return 0;}
