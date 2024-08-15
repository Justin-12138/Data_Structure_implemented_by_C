#include<stdio.h>
#define maxsize 100

typedef struct {
int data[maxsize];
int length;
}sql;

void initialsql(sql *s){
	s->length=0;
}

void tailinsert(sql*s,int elem){
if(s->length>100||s->length<0){
return; 
}
s->data[s->length]=elem;
s->length++;
}

void headinsert(sql*s,int elem){
if(s->length>=100){
return;}
for(int i =s->length;i>0;i--){
s->data[i]=s->data[i-1];
}
s->data[0]=elem;
s->length++;
}

void insert(sql *s,int index,int elem){
if(index<0||index>100||s->length>=100){
return;}
for(int i=s->length;i>index-1;i--){
s->data[i]=s->data[i-1];
}
s->data[index-1]=elem;
s->length++;
}

void headdel(sql*s){
if(s->length<=0){
return;
}
for(int i=0;i<s->length;i++){
s->data[i]=s->data[i+1];
}
s->length--;
}

void taildel(sql *s){
if(s->length<=0){
return;
}
s->length--;
}

void changei(sql *s,int index,int elem){
s->data[index-1]=elem;
}

int searchv(sql *s, int value){
for(int i = 0;i < s->length;i++){
	if(s->data[i]==value){
	return i+1;

}}}

int searchi(sql*s,int index){
if(index>100||index<0){
return 10086;
}
return s->data[index-1];
}

void changev(sql *s,int target,int source){
int index = searchv(s,source);
changei(s,index,target);
}

void indexdel(sql*s,int index){
if(s->length<=0){
return;
}
for(int i = index-1;i<s->length;i++){
s->data[i]=s->data[i+1];
}
s->length--;
}


void valuedel(sql *s,int elem){
if(s->length<=0){
return;
}
int index = searchv(s,elem);
indexdel(s,index);
}

void ptf(sql *s){
printf("sql.length=%d\n",s->length);
for(int i =0;i<s->length;i++){
printf("elem[%d] of sql:%d\n",i+1,s->data[i]);}
}


int main(){
sql s1;
initialsql(&s1);
tailinsert(&s1,1);
tailinsert(&s1,2);
headinsert(&s1,0);
insert(&s1,2,22);
changev(&s1,222,22);

ptf(&s1);

int index = searchv(&s1,222);
printf("search by value(222) get index:%d\n",index);
printf("search by index(4) get value:%d\n",searchi(&s1,4));

printf("---------------------del 222-----------------------\n");
valuedel(&s1,222);
ptf(&s1);

printf("-------------------del index1-----------------------\n");
indexdel(&s1,1);
ptf(&s1);

printf("-------------------del head-----------------------\n");
headdel(&s1);
ptf(&s1);

printf("-------------------del tail-----------------------\n");
taildel(&s1);
ptf(&s1);


return 0;
}