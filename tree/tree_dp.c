#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define maxsize 100

typedef struct treenode
{
    int data;
    int parent;
}treenode;

typedef struct tree
{
    treenode data[maxsize];
    int count;
}tree;


void inittree(tree*t){
t->count=0;
}


int main(){



    return 0;
}