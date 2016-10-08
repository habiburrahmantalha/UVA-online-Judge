#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

void print(int x,int i)
{
    if(i==12)
    {
        if(x&1)
        printf("1");
        else
        printf("0");
        return;
    }
    print(x>>1,i+1);
    if(x&1)
    printf("1");
    else
    printf("0");
}
int main()
{
    int a,b,tc;
    char s[10];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%X %s %X",&a,s,&b);
        if(s[0]=='+')
        {
            print(a,0);
            printf(" + ");
            print(b,0);
            printf(" = %d\n",a+b);
        }
        if(s[0]=='-')
        {
            print(a,0);
            printf(" - ");
            print(b,0);
            printf(" = %d\n",a-b);
        }
    }
    return 0;
}
