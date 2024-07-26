#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    
    int x;
    int y;

}point;


// point* init_point(int x,int y){
//     point* newpoint=(point*)malloc(sizeof(point));
//     if (newpoint==NULL)
//     {
//         printf("Memory allocate failed!");
//         return;
//     }
//     newpoint->x=x;
//     newpoint->y=y;
//     return newpoint;
// }

void init_point(point *p,int x,int y){
    

    p->x=x;
    p->y=y;
}

void calc_d(point p){
    


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
    init_point(&p1,3,4);
    ptf(&p1);
    return 0;
}
