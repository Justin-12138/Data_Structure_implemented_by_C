#include<stdio.h>
#define maxsize 100
typedef int ElemType;
typedef struct
{
	ElemType data[maxsize];
	int length;
}sql;

void init_sql(sql*s)
{
	s->length=0;
}

void insert_end(sql*s,ElemType elem)
{
	s->data[s->length]=elem;
	s->length++;
}
void insert_head(sql*s,ElemType elem){
	for(int i = s->length;i>0;i--)
	{
		s->data[i]=s->data[i-1];
	}
	s->data[0]=elem;
	s->length++;
}

void insert_index(sql*s,int index,ElemType elem)
{
	if(index<=0||index>s->length+1||index>maxsize||s->length>=maxsize)
	{
		printf("index is illegal!\n");
		return ;
	}
	for(int i=s->length-1;i>index-1;i--){
		s->data[i+1]=s->data[i];
	}
	s->data[index-1]=elem;
	s->length++;
}

void del_head(sql*s){
	if(s->length<=0){
		printf("there is no elems in sql!!!");
		return;
	}
	for(int i=0;i<s->length;i++){
		s->data[i]=s->data[i+1];
	}
	s->length--;
}


void del_tail(sql*s){
	if(s->length<=0){
		printf("there is no elems in sql!!!\n");
	}
	s->length--;

}


void del_by_index(sql*s,int index)
{
	if(index<=0||index>s->length||index>maxsize)
	{
		printf("index is illegal!\n");
		return ;
	}
	
	for(int i = index-1;i<s->length-1;i++)
	{
		s->data[i] = s->data[i+1];
	}
	s->length--;
}
void del_by_value(sql*s,ElemType elem)
{
	for(int i=0;i<s->length;i++)
	{
		if(s->data[i]==elem)
		{
			s->data[i]=s->data[i+1];
		}
	}
	s->length--;	
}

void change_by_index(sql*s,int index,ElemType value)
{
	s->data[index+1] = value;
}


int search_by_value(sql*s,ElemType value)
{
	for(int i=0;i<s->length;i++)
	{
		if(s->data[i]==value)
		{
		return i+1;
		}
	}
}


ElemType search_by_index(sql*s,int index)
{
	return s->data[index-1];
}


void ptf_elems(sql*s)
{
for (int i=0;i<s->length;i++)
{
	printf("current elems[%d]:%d\n",i+1,s->data[i]);	
}
}


int main(){
	sql s1;
	init_sql(&s1);
	insert_end(&s1,1);
	insert_end(&s1,2);
	insert_end(&s1,3);
	del_by_index(&s1,10);
	del_by_index(&s1,1);	
	del_by_value(&s1,3);	

	insert_end(&s1,4);
        insert_end(&s1,5);
        insert_end(&s1,6);
        insert_end(&s1,7);
	change_by_index(&s1,3,10086);	
	insert_index(&s1,2,10010);
	
	
	ElemType value = search_by_value(&s1,10086);
	int index = search_by_index(&s1,3);
	insert_head(&s1,100);
	insert_head(&s1,10);	
	del_tail(&s1);
	printf("search_by_value(10086):%d\n",value);
	printf("search_by_index(3):%d\n",index);
	printf("current length:%d\n",s1.length);
	ptf_elems(&s1);


return 0;
}
