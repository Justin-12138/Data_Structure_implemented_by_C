#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int main(){
    char ch1='2';
    // no matter how long the string,the sizeof(arr) is 8 for 64 bit OS,4 for 32 bit OS;
    // 
    char *str_ptr = "jjj";
    
    // the length of this kind definition = n+1,1 for the end signal \0; 
    // if you define clearly char[3]="www",it won't add the \0 to the end of "www";
    // by the way,the type of each 'w' and 'j' in "www","jjj" is char
    char str[] = "www";
    printf("length of str:%ld\nlength of str_ptr:%ld\n",sizeof(str_ptr),sizeof(str));
    for (int i = 0; i < sizeof(str)-1; i++)
    {
        printf("%c\n",str[i]);
    }
    
    for (int j = 0; j < 3; j++)
    {
        printf("%c\n",str_ptr[j]);
    }
    








    


    // char only '' %c
    // char arr[4]={'a','b','c','2'};

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
