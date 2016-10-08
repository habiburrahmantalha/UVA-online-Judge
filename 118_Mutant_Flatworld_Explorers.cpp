#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

int X[]={0,1,0,-1};
int Y[]={1,0,-1,0};
char dir[]={"NESW"};
int n,m,g[55][55];
char op[10001];
bool valid(int x,int y)
{
    if(x<0 || x >n || y<0 || y>m)
        return false;
    return true;
}
void Explorers(int cx,int cy,int d)
{
    int nx,ny;
    char ch;

    for(int o=0;o<strlen(op);o++)
    {
        ch=op[o];
        if(ch=='F')
        {
            nx=cx+X[d];
            ny=cy+Y[d];
            if(valid(nx,ny))
            {
                cx=nx;
                cy=ny;
            }
            else
            {
                if(!g[cx][cy])
                {
                    printf("%d %d %c LOST\n",cx,cy,dir[d]);
                    g[cx][cy]=true;
                    return;
                }

            }
        }
        else if(ch=='R')
        {
            d=(d+1)%4;
        }
        else if(ch=='L')
        {
            d=(d+3)%4;
        }
        //printf("%d %d %c\n",cx,cy,dir[d]);
    }
    printf("%d %d %c\n",cx,cy,dir[d]);
}
int direction(char d)
{
    if(d=='N')
        return 0;
    else if(d=='E')
        return 1;
    else if(d=='S')
        return 2;
    else if(d=='W')
        return 3;
}
int main()
{
    //freopen("in.txt","r",stdin);
    memset(g,false,sizeof(g));
    int sx,sy;
    char sd;
    scanf("%d %d",&n,&m);
    while(cin>>sx>>sy>>sd)
    {
        cin>>op;
        Explorers(sx,sy,direction(sd));
    }
    return 0;
}
