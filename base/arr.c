#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define maxsize 100
typedef struct string
{
    char data[maxsize];
    int length;
}str;

void initstring(str *str){
str->length=0;
}
void crate(str*s,char){

}




int main(){

// char only '' %c
// int arr[4]={'a','b','c','2'};

// for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
// {
//     printf("arr[%d]:%c\n",i+1,arr[i]);
// }

//string char[]={"a44bc"} as a matter of fact \0 at the end of the string,so the length is 6
// the type of whole string "a44bc" use the %s!!!

// char str[]="a44bc";
// printf("str:%s,length:%ld\n",str,sizeof(str)/sizeof(str[0]));

//if you asign the length char str1[4]="abcd",it wont't create the \0 as singal of end!
//at the same time,the type of every single letter must use the %c!!!

// for (int j = 0; j < sizeof(str)/sizeof(str[0]); j++)
// {
//     printf("str[%d]:%c\n",j+1,str[j]);
// }
// char str1[4]={"1221"};
// for (int i = 0; i < sizeof(str1)/sizeof(str1[0]); i++)
// {
//     printf("str1[%d]:%c\n",i+1,str1[i]);
// }




    return 0;
}
