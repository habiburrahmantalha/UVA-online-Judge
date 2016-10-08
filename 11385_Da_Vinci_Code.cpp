#include <string.h>
#include <map>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include<string>
#define LL long long
using namespace std;

map <int,int> fib;

void gen_fib ()
{
    int f[50],i;
    f[0]=1;
    f[1]=2;
    fib[0]=0;
    fib[2]=1;
    for(i=2;i<45;i++)
    {
        f[i]=f[i-1]+f[i-2];
        fib[f[i]]=i;
    }
}


int main()
{
    gen_fib();

    int tc,n,i,x,max,in;
    int p[110];
    char ch,text[110],out[110];

    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);
        max=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            p[i]=fib[x];
            if(max<x)
                max=x;
                //printf("%d ",p[i]);
        }
        in=0;
        getchar();
        while(1)
        {
            ch=getchar();
            if(ch=='\n')
                break;
            if(isupper(ch))
            {
                text[in++]=ch;
            }
        }
        text[in]=0;

        memset(out,' ',sizeof(out));
        out[fib[max]+1]='\0';

        for(i=0;i<n;i++)
        {
            out[p[i]]=text[i];
        }

        printf("%s\n",out);
    }
    return 0;
}
