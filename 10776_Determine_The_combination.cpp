#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

int n,l;
char s[100],x[100];

void backtrack(int i,int k)
{
    x[k]=s[i];
    if(k==n-1)
    {
        x[k+1]=0;
        printf("%s\n",x);
        return;
    }
    for(int j=i+1;j<l;j++)
        backtrack(j,k+1);
}
int main()
{
    int i;
    while(scanf("%s %d",s,&n)==2)
    {
        l=strlen(s);
        sort(s,s+l);
        for(i=0;i<l;i++)
        {
            if(i>0 && s[i]==s[i-1])
            continue;
            backtrack(i,0);
        }
    }
    return 0;
}
