#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define maxsize 5
typedef int elemtype;
typedef struct Queue
{
    int rear,font;
    elemtype data[maxsize];
}Queue;

void initqueue(Queue*q){
    q->rear=-1;
    q->font=0;
}

void ptf_line(){
    printf("--------------------------------\n");
}
bool isfull(Queue*q){
    return (q->rear>=maxsize-1) ? true:false;
}

bool isempty(Queue*q){
    return (q->rear==-1)?true:false;
}

void inqueue(Queue*q,elemtype elem){    
    q->data[++q->rear]=elem;
}

elemtype ouqueue(Queue*q){
    if (isempty(q))
    {
        return 10086;
    }
    q->rear=q->rear-1;
    return q->data[q->font];
}

void main(){
    Queue q1;
    initqueue(&q1);
    printf("empty?:%d\n",isempty(&q1));
    ptf_line();

    inqueue(&q1,11);
    inqueue(&q1,12);
    inqueue(&q1,13);
    inqueue(&q1,14);
    inqueue(&q1,15);
    printf("full?:%d\n",isfull(&q1));
    printf("queue 's top elem:%d\n",ouqueue(&q1));
    printf("full?:%d\n",isfull(&q1));
    ptf_line();
    ouqueue(&q1);
    ouqueue(&q1);
    ouqueue(&q1);
    ouqueue(&q1);
    printf("empty?:%d\n",isempty(&q1));
    printf("queue 's top elem:%d\n",ouqueue(&q1));

}