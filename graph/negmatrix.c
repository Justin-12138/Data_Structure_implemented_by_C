#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define maxver 100

typedef char vertype;
typedef struct Graph{
    int numvers;
    int grp[maxver][maxver];
}Graph; 

void initial(Graph*g,int numver){
    
    if (numver<=0||numver>maxver)
    {
        printf("numvers is out of range!");
        return;
    }
    g->numvers=numver;
    for (int i = 0; i < numver; i++)
    {
        for (int j = 0; j < numver; j++)
        {
            g->grp[i][j]=0;
        }
    }
}

void ptf(Graph*g){
    printf("g->numvers:%d\n",g->numvers);
    if (g->numvers==0)
    {
        printf("graph is empty!");
        return;
    }
    for (int i = 0; i < g->numvers; i++)
    {
        for (int j = 0; j < g->numvers; j++)
        {
            printf("%d ",g->grp[i][j]);
        }
        printf("\n");
    }
    printf("---------------------\n");
}

void createedge(Graph*g,int in,int jn,bool dir,bool net,int weight){
    if (in<0||in>g->numvers||jn<0||jn>g->numvers||in==jn)
    {
        printf("index out of range!\n");
        return;
    }
    if (!net)
    {
        if (dir)
        {
            g->grp[in-1][jn-1]=1;
            return;
        }
        else{
            g->grp[in-1][jn-1]=1;
            g->grp[jn-1][in-1]=1;
            return;
        }
    }
    else{

        if (dir)
        {
            g->grp[in-1][jn-1]=weight;
            return;
        }
        else{
            g->grp[in-1][jn-1]=weight;
            g->grp[jn-1][in-1]=weight;
            return;
        }
    }
}

int calcdr(Graph*g,int index,bool dir,bool net){
    if (index<0||index>g->numvers)
    {
        printf("index out of range!\n");
        return 0;
    }
    int dy = 0;
    if (!dir)
    {

        if (!net)
        {
            for (int i = 0; i < g->numvers; i++)
            {

                dy+=g->grp[index-1][i];
            }
        return dy;
        }
        else{
            int i = 0;
            while (i<g->numvers)
            {
                if (g->grp[index-1][i]!=0)
                {
                    dy+=1;
                }
                i+=1;
            }
        return dy;
        }
    }
    else{
        for (int i = 0; i < g->numvers; i++)
        {
            if (g->grp[index-1][i]!=0)
            {
                dy+=1;
            }
            if (g->grp[i][index-1])
            {
                dy+=1;
            }
        }
        return dy;
    }
}



void main(){
    // 无向无权图
    Graph g1;
    initial(&g1,5);
    createedge(&g1,3,4,false,false,0);
    createedge(&g1,1,2,false,false,0);
    createedge(&g1,4,5,false,false,0);
    createedge(&g1,3,1,false,false,0);
    printf("dy of ver 3:%d\n",calcdr(&g1,3,false,false));
    ptf(&g1);

    // 无向有权图
    Graph g2;
    initial(&g2,4);
    createedge(&g2,3,4,false,true,5);
    createedge(&g2,1,2,false,true,9);
    createedge(&g2,4,1,false,true,1);
    printf("dy of ver 1:%d\n",calcdr(&g2,1,false,true));

    ptf(&g2);

    // 有向无权图
    Graph g3;
    initial(&g3,3);
    createedge(&g3,1,2,true,false,0);
    createedge(&g3,1,3,true,false,0);
    createedge(&g3,3,1,true,false,0);
    printf("dy of ver 3:%d\n",calcdr(&g3,3,true,true));
    ptf(&g3);

    // 有向有权图
    Graph g4;
    initial(&g4,6);
    createedge(&g4,1,2,true,true,3);
    createedge(&g4,1,3,true,true,4);
    createedge(&g4,3,1,true,true,4);
    createedge(&g4,4,5,true,true,9);
    createedge(&g4,6,5,true,true,8);
    createedge(&g4,5,1,true,true,6);
    printf("dy of ver 5:%d\n",calcdr(&g4,5,true,true));
    ptf(&g4);


}