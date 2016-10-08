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
#define LL long long

LL fact(LL x)
{
    LL y=1,i;
    for(i=1;i<=x;i++)
    y*=i;

    return y;
}
int main()
{
    int tc,t=1,f[30],i;
    char str[30];
    LL x;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(f,0,sizeof(f));
        scanf("%s",str);
        for(i=0;str[i];i++)
        f[str[i]-'A']++;

        x=fact(strlen(str));
        for(i=0;i<26;i++)
        if(f[i]>1)
        x/=fact(f[i]);

        printf("Data set %d: %lld\n",t++,x);
    }
    return 0;
}
