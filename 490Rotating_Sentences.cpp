#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    char a[110][110];
    memset(a,0,sizeof(a));
    int in=0,i,j,k,max=0;

    while(gets(a[in]))
    {
        if(strlen(a[in])>max)
        max=strlen(a[in]);

        in++;
    }

    for(i=0;i<in;i++)
    for(j=0;j<max;j++)
    if(a[i][j]==0)
    a[i][j]=' ';


    for(i=0;i<max;i++){
    for(j=in-1;j>=0;j--)
    printf("%c",a[j][i]);
    printf("\n");
    }

    return 0;
}
