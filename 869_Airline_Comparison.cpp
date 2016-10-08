#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;
int g1[200][200],g2[200][200];

void warshal(int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                {
                    if(g1[i][j]<g1[i][k]+g1[k][j])
                    g1[i][j]=1;
                    if(g2[i][j]<g2[i][k]+g2[k][j])
                    g2[i][j]=1;
                }
            }

}

bool equal(int n,int m)
{
    int i,j;
    if(n!=m)
        return false;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(g1[i][j]!=g2[i][j])
                return false;

    return true;

}
void reset()
{
    int i,j;
    for(i=0;i<200;i++)
        for(j=0;j<200;j++)
        {
            g1[i][j]=g2[i][j]=10000;
        }
}
int main()
{
    int n,m,N,M,tc,i,j;
    bool f=false;
    string ch1,ch2;
    map<string,int> mp1;
    map<string,int> mp2;
    scanf("%d",&tc);
    while(tc--)
    {
        if(f)
            printf("\n");

        reset();
        scanf("%d",&n);
        N=1;
        for(i=0;i<n;i++)
        {
            cin>>ch1>>ch2;
            if(!mp1[ch1])
                mp1[ch1]=N++;
            if(!mp1[ch2])
                mp1[ch2]=N++;
            g1[mp1[ch1]][mp1[ch2]]=1;

        }

        scanf("%d",&m);
        M=1;

        for(j=0;j<m;j++)
        {
            cin>>ch1>>ch2;
            if(!mp2[ch1])
                mp2[ch1]=M++;
            if(!mp2[ch2])
                mp2[ch2]=M++;
            g2[mp2[ch1]][mp2[ch2]]=1;

        }

        if(N==M)
        warshal(N);
        if(equal(N,M))
            printf("YES\n");
        else
            printf("NO\n");
        f=true;
        mp1.clear();
        mp2.clear();

    }
    return 0;
}
