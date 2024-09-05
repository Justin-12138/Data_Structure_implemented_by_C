#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int elemtype;

typedef struct dysql
{
    elemtype *data;
    int length;
    int capacity;
}dysql;

void initdysql(dysql*d,int initcapacity){
d->length=0;
d->capacity=initcapacity;
d->data=(elemtype*)malloc(sizeof(elemtype)*initcapacity);
if (d->data==NULL)
{
    return;
}
}

void extend(dysql*d){
    elemtype*newdata=(elemtype*)realloc(d->data,d->capacity*2);
    if (newdata==NULL)
    {
        return;
    }
    d->data=newdata;
    d->capacity=d->capacity*2;
}

void headinsert(dysql*d,elemtype elem){
if (d->length>=d->capacity)
{
    extend(d);
}
for (int i=d->length; i > 0 ; i--)
{
    d->data[i]=d->data[i-1];
}
d->data[0]=elem;
d->length++;
}

void tailinsert(dysql*d,elemtype elem){
    if (d->length>=d->capacity)
    {
        extend(d);
    }
    d->data[d->length]=elem;
    d->length++;
}

void insert(dysql*d,elemtype elem,int index){
    if (d->length>=d->capacity)
    {
        extend(d);
    }
    for (int i = d->length; i > index-1; i--)
    {
        d->data[i]=d->data[i-1];
    }
    d->data[index-1]=elem;
    d->length++;
}

elemtype indexsearch(dysql*d,int index){
    if (index>d->length||index<0)
    {
        return 10000;
    }
    return d->data[index-1];
}

int valuesearch(dysql*d,elemtype elem){
    if (d->length==0)
    {
        return 1000;
    }
    for (int i = 0; i < d->length; i++)
    {
        if (d->data[i]==elem)
        {
            return i+1;
        }   
    }
}

void indexdel(dysql*d,int index){
    if (d->length==0)
    {
        printf("dysql is blank!\n");
        return;
    }
    for (int i = index-1; i < d->length; i++)
    {
        d->data[i]=d->data[i+1];
    }
    d->length--;
}

void valuedel(dysql*d,elemtype elem){
    if (d->length==0)
    {
        return;
    }
    int index=valuesearch(d,elem);
    indexdel(d,index);
}

void ptf(dysql*d){
    printf("---------------------------\n");
    printf("dysql->length:%d,dysql->capacity:%d\n",d->length,d->capacity);
    if (d->length==0)
    {
        printf("dysql is blank!\n");
        return;
    }
    
    for (int i = 0; i < d->length; i++)
    {
        printf("elem[%d]:%d\n",i+1,d->data[i]);
    }
    
    
}

void clear(dysql*d){
    free(d->data);
    d->length=0;
    d->capacity=0;
}

void swap(elemtype*a,elemtype*b){
    elemtype swap;
    swap=*a;
    *a=*b;
    *b=swap;
}

dysql*bublerank(dysql*d,bool ascend){
    for (int i = 0; i < d->length-1; i++)
    {
        for (int j = 0; j < d->length-1; j++)
        {
            if (ascend)
            {
                if (d->data[j]>d->data[j+1])
                {
                    swap(&d->data[j+1],&d->data[j]);
                }
            }
            else{
                if (d->data[j]<d->data[j+1])
                {
                    swap(&d->data[j],&d->data[j+1]);
                }
            }
            
        }
        
    }
    return d;
}

dysql*dirank(dysql*d,bool ascend){



    return d;
}


dysql*inverse(dysql*d){
    for (int i = 0;i<d->length/2; i++)
    {
        swap(&d->data[i],&d->data[d->length-1-i]);
    }
}









int main(){
    dysql d1;
    initdysql(&d1,3);
    ptf(&d1);

    headinsert(&d1,11);
    headinsert(&d1,12);
    tailinsert(&d1,44);
    tailinsert(&d1,10086);
    ptf(&d1);

    indexdel(&d1,1);
    valuedel(&d1,10086);
    ptf(&d1);

    insert(&d1,32,3);
    tailinsert(&d1,33);
    headinsert(&d1,9);
    bublerank(&d1,false);
    ptf(&d1);

    inverse(&d1);
    ptf(&d1);


    clear(&d1);
    ptf(&d1);

    return 0;
}


