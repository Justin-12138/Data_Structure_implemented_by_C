#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define maxsize 5
typedef int elemtype;
typedef struct Stack
{
    elemtype data[maxsize];
    int top;
}Stack;

void initstack(Stack*s){
    s->top=-1;
}

bool isempty(Stack*s){
    return (s->top==-1) ? true:false;
}

bool isfull(Stack*s){
    return (s->top>=maxsize-1) ? true:false;
}

void ptf_line(){
    printf("----------------\n");
}

void push(Stack*s,elemtype elem){
    if (isfull(s))
    {
        printf("stack is full!\n");
        return;
    }
    s->data[++s->top]=elem;
}

elemtype pop(Stack*s){
    if (isempty)
    {
        printf("Stack is empty!\n");
        return 10086;
    }
    return s->data[s->top--];
}


elemtype peek(Stack*s){
    if (isempty(s))
    {
        printf("stack is empty!");
        return 10086;
    }
    return s->data[s->top];
}

void main(){
    Stack s1;
    initstack(&s1);
    pop(&s1);
    printf("empty?:%d\n",isempty(&s1));
    ptf_line();
    push(&s1,1);
    push(&s1,12);
    push(&s1,11);
    printf("empty?:%d\n",isempty(&s1));
    elemtype top =peek(&s1);
    printf("peek elem:%d\n",top);
    ptf_line();
    push(&s1,22);
    push(&s1,33);
    printf("full?:%d\n",isfull(&s1));
    ptf_line();
    pop(&s1);
    elemtype top2 =peek(&s1);
    printf("peek elem:%d\n",top2);
    ptf_line();
    push(&s1,44);
    
    
}