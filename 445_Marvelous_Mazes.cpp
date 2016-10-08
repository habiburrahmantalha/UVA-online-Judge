#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    char ch,str[10000];
    int i,n=0;
    while(gets(str))
    {
        if(strlen(str)!=0)
        for(i=0;i<strlen(str);i++){
        if(str[i]=='!' || str[i]=='\n')
        {
            if(n==0)
                printf("\n");
            while(n--)
                printf("\n");
            n=0;
        }
        else if(isdigit(str[i]))
        {
            n=0;
            while(isdigit(str[i]))
            {
                n+=(str[i]-'0');
                i++;

            }
            i--;

        }
        else if(str[i]=='b' || str[i]==' ')
        {
            if(n==0)
                printf(" ");
            while(n--)
            printf(" ");
            n=0;
        }
        else
        {
            if(n==0)
                printf("%c",str[i]);
            while(n--)
                printf("%c",str[i]);
            n=0;
        }

    }
    printf("\n");
    }
    return 0;
}
