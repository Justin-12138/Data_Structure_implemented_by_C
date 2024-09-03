#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define maxsize 100

typedef int elemtype;
typedef struct sql
{
    elemtype data[maxsize];
    int length;
}sql;

void initsql(sql*s){
    s->length=0;
}

void headinsert(sql*s,elemtype elem){
    if (s->length>=maxsize)
    {
        return;
    }
    for (int i = s->length; i > 0; i--)
    {
        s->data[i]=s->data[i-1];   
    }
    s->data[0]=elem;
    s->length++;
}

void tailinsert(sql*s,elemtype elem){
    if (s->length>maxsize)
    {
        return;
    }
    s->data[s->length]=elem;
    s->length++;
}

void insert(sql*s,elemtype elem,int index){
    if (s->length>maxsize||index>s->length)
    {
        return;
    }
    // especially index - 1;
    for (int i = s->length; i > index-1; i--)
    {
        s->data[i]=s->data[i-1];
    }
    s->data[index-1]=elem;
    s->length++;
}

int valuesearch(sql*s,elemtype elem){
// assume that every elem is different; 
for (int i = 0; i < s->length; i++)
{
    if (s->data[i]==elem)
    {
        return i+1;
    }
}
}

elemtype indexsearch(sql*s,int index){
    return s->data[index-1];
}

void indexdelete(sql*s,int index){
    if (s->length==0||index<=0||index>maxsize)
    {
        return;
    }
    for (int i = index-1; i < s->length; i++)
    {
        s->data[i]=s->data[i+1];
    }
    s->length--;
}

void valuedelete(sql*s,elemtype elem){
    if (s->length==0)
    {
        return;
    }
    int index = valuesearch(s,elem);
    indexdelete(s,index);
}

void indexchange(sql*s,int index,elemtype target){
    s->data[index-1]=target;
}

void valuechange(sql*s,elemtype source,elemtype target){
    int index=valuesearch(s,source);
    indexchange(s,index,target);
}

void ptf(sql*s){
    for (int i = 0; i < s->length; i++)
    {
        printf("elem[%d]:%d\n",i+1,s->data[i]);
    }
    printf("sql's length:%d\n",s->length);
    printf("----------------------------\n");
    
}

void swap(int *a,int*b){
    int swap;
    swap=*a;
    *a=*b;
    *b=swap;
}

sql* bublerank(sql*s,bool ascend){
    for (int i = 0; i < s->length-1; i++)
    {
        for (int j = 0; j < s->length-1; j++)
        {
            if (ascend)
            {
                if (s->data[j]>s->data[j+1])
                    {
                        swap(&s->data[j],&s->data[j+1]);
                    }
            }
            else
            {
                if (s->data[j]<s->data[j+1])
                    {
                        swap(&s->data[j],&s->data[j+1]);
                    }
            }  
        }   
    }
    return s;
}

sql* dirank(sql*s,bool ascend){
    for (int i = 1; i < s->length; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (ascend)
            {
                if (s->data[j-1]>s->data[j])
                {
                    swap(&s->data[j-1],&s->data[j]);
                }
            }
            else
            {
                if (s->data[j-1]<s->data[j])
                {
                    swap(&s->data[j-1],&s->data[j]);
                }
                
            }
            
        }
        
    }
    

}

sql* serank(sql*s,bool ascend){
    for (int i = 0; i < s->length; i++)
    {
        for (int j = i+1; j < s->length; j++)
        {
            if (ascend)
            {
                if (s->data[j] < s->data[i])
                {
                    swap(&s->data[j],&s->data[i]);
                }
            }
            else
            {
                if (s->data[j] > s->data[i])
                {
                    swap(&s->data[j],&s->data[i]);
                }   
            }
        }   
    }   
}

elemtype find_max_min(sql*s,bool max){
    elemtype init=s->data[0];
    for (int i = 0; i < s->length; i++)
    {
        if (max)
        {
            if (s->data[i]>init)
            {
                init=s->data[i];
            }
                
        }
        else
        {
            if (s->data[i]<init)
            {
                init=s->data[i];
            }   
        } 
    }

    return init;
}

sql* inverse(sql*s){
    for (int i = 0; i < s->length/2; i++)
    {
        swap(&s->data[i],&s->data[s->length-i-1]);
    }
    return s;
}




int main(){
    sql s1;
    // base!!!
    initsql(&s1);

    headinsert(&s1,100);
    tailinsert(&s1,99);
    headinsert(&s1,101);
    headinsert(&s1,88);
    tailinsert(&s1,77);
    insert(&s1,11,3);
    insert(&s1,10086,1);
    ptf(&s1);

    indexdelete(&s1,1);
    valuedelete(&s1,99);
    ptf(&s1);

    indexchange(&s1,1,911);
    valuechange(&s1,77,911);
    ptf(&s1);


    bublerank(&s1,true);
    ptf(&s1);
    printf("max:%d,min:%d\n",find_max_min(&s1,true),find_max_min(&s1,false));
    
    inverse(&s1);
    ptf(&s1);

    insert(&s1,1000,1);
    dirank(&s1,true);
    ptf(&s1);

    valuedelete(&s1,11);
    serank(&s1,true);
    ptf(&s1);

    return 0;
}



