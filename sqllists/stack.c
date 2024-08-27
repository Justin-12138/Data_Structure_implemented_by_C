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
