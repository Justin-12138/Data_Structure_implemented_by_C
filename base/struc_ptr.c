#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    
    int x;
    int y;

}point;

void init_point(point *p,int x,int y){
    p->x=x;
    p->y=y;
}

double calc_d(point *p1,point *p2){

    float dis = ((p1->x-p2->x)^2+(p1->y-p2->y)^2)^(1/2);
    return dis;
}


void del(point *p){
    free(p);
    p=NULL;
}


void ptf(point *p){
    printf("x:%d\n",p->x);
    printf("y:%d\n",p->y);
}

int main()
{
    point p1;
    point p2;
    init_point(&p2,0,0);
    init_point(&p1,3,4);
    double dis = calc_d(&p1,&p2);
    printf("dis between p1 and p2:%2f",dis);
    
    ptf(&p1);
    
    return 0;
}
