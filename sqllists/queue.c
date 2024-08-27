#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

# define maxsize 100

typedef struct queue
{
    int data[maxsize];
    int front;
    int rear; 
}queue;


void initqueue(queue*q){
    q->front=0;
    q->rear-1;
}

bool isfull(queue*q){
if (q->front==maxsize-1)
{
    return true;
}
else
{
    return false;
}
}

bool isempty(queue*q){
if (q->rear==-1)
{
    return true;
}
else {
    return false;
}
}

void inqueue(queue*q,int data){
if (q->front>=maxsize)
{
    
}


}









int main()
{
    
    return 0;
}
