//Problem Type :    grid travarse
//Time :    0.008
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)

char G[110][110];
int D[110][110];

void travarse(int xs,int ys,int zs)
{
    int x,y,z,u,v,w,a,b;
    memset(D,0,sizeof(D));

    u=xs;
    v=ys;
    w=zs;
    //int cnt=1;
    while(true)
    {

        if(w==1)
        {
            x=u;
            y=v+1;
            z=w;
            a=u+1;
            b=v;
            //cout<<D[x][y]<<" ";
            if(G[a][b]=='0')
            {
                x=a;y=b;z=2;
                D[x][y]++;
                //cout<<cnt++<<" >v";
            }
            else if(G[x][y]=='1')
            {
                x=u;y=v;z=3;
                //cout<<cnt++<<" >^";
            }
            else
                D[x][y]++;


        }
        else if(w==2)
        {
            x=u+1;
            y=v;
            z=w;
            a=u;
            b=v-1;
            //cout<<D[x][y]<<" ";
            if(G[a][b]=='0')
            {
                x=a;y=b;z=4;
                //cout<<cnt++<<" v<";
                D[x][y]++;
            }
            else if(G[x][y]=='1')
            {
                x=u;y=v;z=1;
                //cout<<cnt++<<" v>";
            }
            else
                D[x][y]++;



        }
        else if(w==3)
        {
            x=u-1;
            y=v;
            z=w;
            a=u;
            b=v+1;
            //cout<<D[x][y]<<" ";
            if(G[a][b]=='0')
            {
                x=a;y=b;z=1;
                D[x][y]++;
                //cout<<cnt++<<" ^>";
            }
            else if(G[x][y]=='1')
            {
                x=u;y=v;z=4;
                //cout<<cnt++<<" ^<";
            }
            else
                D[x][y]++;



        }
        else if(w==4)
        {
            x=u;
            y=v-1;
            z=w;
            a=u-1;
            b=v;
            //cout<<D[x][y]<<" ";
            if(G[a][b]=='0')
            {
                x=a;y=b;z=3;
                D[x][y]++;
                //cout<<cnt++<<" <^";
            }
            else if(G[x][y]=='1')
            {
                x=u;y=v;z=2;
                //cout<<cnt++<<" <v";
            }
            else
                D[x][y]++;


        }
        //cout<<D[x][y]<<endl;
        if(xs==x && ys==y)
        break;
        u=x;
        v=y;
        w=z;
    }



}

int main()
{
    int n,m,i,j,f[10];
    while(scanf("%d %d",&n,&m) && n+m)
    {
        memset(G,'1',sizeof(G));
        G[0][m+2]=0;
        G[n+1][m+2]=0;

        for(i=1;i<=n;i++)
        {
            scanf("%s",G[i]+1);
            G[i][m+1]='1';
            G[i][m+2]=0;
        }

        //for(i=0;i<=n+1;i++)
        //printf("%s\n",G[i]);


        travarse(n,1,1);

        memset(f,0,sizeof(f));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                if(G[i][j]=='0')
                  f[D[i][j]]++;
                //cout<<D[i][j]<<" ";
            //cout<<endl;
        }

        for(i=0;i<5;i++)
        printf("%3d",f[i]);
        printf("\n");
    }
    return 0;
}
