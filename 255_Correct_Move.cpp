#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int k,q,m;
bool illegal_move()
{
    int i,x,y,a,b,u,v,s,e;


    x=q/8;
    y=q%8;

    a=k/8;
    b=k%8;

    u=m/8;
    v=m%8;
    if(u-x!=0 && v-y!=0)
    return true;

    if(x==u)
    {
        s=min(y,v);
        e=max(y,v);
        for(i=s;i<=e;i++)
        if(a==x && b==i)
        return true;
    }
    else
    {
        s=min(x,u);
        e=max(x,u);
        for(i=s;i<=e;i++)
        if(a==i && b==y)
        return true;
    }

    return false;
}
bool stop()
{
    if((k==0 && m==9) || (k==7 && m==14) || (k==56 && m==49) || (k==63 && m==54) )
    return true;

    return false;
}
bool not_allowed()
{
    int x,y,u,v;
    int B[10][10];
    memset(B,0,sizeof(B));
    x=k/8;
    y=k%8;

    u=m/8;
    v=m%8;

    if(x+1<8)
    B[x+1][y]=1;
    if(x-1>=0)
    B[x-1][y]=1;
    if(y+1<8)
    B[x][y+1]=1;
    if(y-1>=0)
    B[x][y-1]=1;

    if(B[u][v]==1)
    return true;

    return false;
}
int main()
{
    //freopen("out.txt","w",stdout);
    while(cin>>k>>q>>m)
    {
        if(k==q)
        printf("Illegal state\n");
        else
        {
            if(k==m || q==m || illegal_move())
            printf("Illegal move\n");
            else
            {
                if(not_allowed())
                    printf("Move not allowed\n");
                else
                {
                    if(stop())
                        printf("Stop\n");
                    else
                        printf("Continue\n");
                }
            }
        }
    }
    return 0;
}
