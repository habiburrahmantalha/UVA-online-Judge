#include<stdio.h>
#include<string.h>
#include<sstream>
#include<iostream>
#include<string>
using namespace std;
#define LL long long
LL n,w;
LL g[1001][1001];



void count_path()
{
    int i,j;
    for(i=1;i<=w;i++)
    {
        g[1][1]=1;
        for(j=1;j<=n;j++)
        if(g[i][j]!=-1)
        {
            if(g[i-1][j]!=-1)
            g[i][j]+=g[i-1][j];
            if(g[i][j-1]!=-1)
            g[i][j]+=g[i][j-1];
        }
    }
}
int main()
{
    LL tc,a,b,i;
    bool f=false;
    char ch,line[10001];
    string str;
    scanf("%lld",&tc);

    while(tc--)
    {
        if(f)
        printf("\n");
        f=true;
        scanf("%lld %lld",&w,&n);
        memset(g,0,sizeof(g));

        gets(line);
        for(i=0;i<w;i++)
        {
            getline(cin,str);
            stringstream ss(str);
            ss>>a;
            while(ss>>b)
            {
                g[a][b]=-1;
            }
        }
        /*
        for(i=1;i<=w;i++)
        {
            for(int j=1;j<=n;j++)
            printf("%d ",g[i][j]);
            printf("\n");
        }
        */
        count_path();
        printf("%lld\n",g[w][n]);
    }
    return 0;
}
