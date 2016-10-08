#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

string p1,p2;
int m1,m2;

struct player
{
    int w;
    int l;
};

player p[101];

void play()
{
    if(p1=="rock")
    {
        if(p2=="paper")
        {
            p[m1].l++;
            p[m2].w++;
        }
        else if(p2=="scissors")
        {
            p[m1].w++;
            p[m2].l++;
        }
    }
    else if(p1=="paper")
    {
        if(p2=="rock")
        {
            p[m1].w++;
            p[m2].l++;
        }
        else if(p2=="scissors")
        {
            p[m1].l++;
            p[m2].w++;
        }
    }
    else if(p1=="scissors")
    {
        if(p2=="rock")
        {
            p[m1].l++;
            p[m2].w++;
        }
        else if(p2=="paper")
        {
            p[m1].w++;
            p[m2].l++;
        }
    }
}
void reset(int N)
{
    for(int i=0;i<=N;i++)
    {
        p[i].w=0;
        p[i].l=0;
    }
}
int main()
{

    int i,N,K,game;
    double res;
    bool f=false;
    while(scanf("%d",&N) && N)
    {
        if(f)
            printf("\n");
        reset(N);
        scanf("%d",&K);
        game=(K*N*(N-1))/2;
        for(i=0;i<game;i++)
        {
            cin>>m1>>p1>>m2>>p2;
            play();
        }
        for(i=1;i<=N;i++)
        {
            if(p[i].w+p[i].l==0)
            {
                printf("-\n");
                continue;
            }
            res= double(p[i].w)/double(p[i].w+p[i].l);
            printf("%.3lf\n",res);
        }
        f=true;

    }
    return 0;
}
