#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
    int tc,i,f,m;
    char str[10000];
    scanf("%d",&tc);
    while(tc--)
    {
        f=m=0;
        scanf("\n");
        gets(str);
        for(i=0;str[i];i++)
        if(str[i]=='F')
        f++;
        else if(str[i]=='M')
        m++;

        if(f==m && f!=1)
        printf("LOOP\n");
        else
        printf("NO LOOP\n");
    }
    return 0;
}
