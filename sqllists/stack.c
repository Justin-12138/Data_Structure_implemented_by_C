<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // 栈的最大容量

typedef struct {
    int data[MAX];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 判断栈是否满
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// 入栈
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("栈满，无法入栈\n");
        return;
    }
    s->data[++(s->top)] = value;
    printf("s->top:%d\n",s->top);
}

// 出栈
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("栈空，无法出栈\n");
        return -1; // 返回-1表示栈空
    }
    return s->data[(s->top)--];
}

// 获取栈顶元素
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("栈空，无栈顶元素\n");
        return -1; // 返回-1表示栈空
    }
    return s->data[s->top];
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    // printf("栈顶元素: %d\n", peek(&s));
    // printf("出栈: %d\n", pop(&s));
    // printf("出栈: %d\n", pop(&s));
    // printf("出栈: %d\n", pop(&s));
    // printf("出栈: %d\n", pop(&s)); // 栈空测试

    return 0;
}
=======
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

>>>>>>> 725a211b449973bdfed7810ab78009083d80f151
