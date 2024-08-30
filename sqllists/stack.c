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

void clearstack(stack*s){
    s->top==-1;
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

int peek(stack*s){
    return s->data[s->top--];
}

void ptf(stack*s){
    printf("-----------------------\n");
    for (int i = 0; i < s->top+1; i++)
    {
        printf("elem[%d]:%d\n",i+1,s->data[i]);
    }
}



int main(){
stack s1;
initstack(&s1);
isempty(&s1);
push(&s1,5);
push(&s1,4);
printf("lenght of stack:%d\n",s1.top+1);


push(&s1,3);
printf("lenght of stack:%d\n",s1.top+1);

push(&s1,10086);
printf("top elem:%d\n",pop(&s1));
printf("lenght of stack:%d\n",s1.top+1);


printf("top elem:%d\n",peek(&s1));

isfull(&s1);

push(&s1,10086);
ptf(&s1);
clearstack(&s1);
push(&s1,10086);
push(&s1,10086);
push(&s1,10086);

// ptf(&s1);

return 0;}
