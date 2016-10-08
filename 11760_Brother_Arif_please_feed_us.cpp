#include<stdio.h>
#include<string.h>

int C[10],r,c,a[2010][3];
int X[]={0,0,-1,0,1};
int Y[]={0,-1,0,1,0};
bool valid(int x,int y)
{
    if(x<0 ||x>=r || y<0 || y>=c)
    return false;
    return true;
}
bool captured(int i,int j,int u,int v)
{
    int k,x,y;
    for(k=0;k<5;k++)
    {
        x=u+X[k];
        y=v+Y[k];
        if(valid(x,y))
        {
            if(x==i || y==j)
            C[k]=1;
        }
        else
        C[k]=1;
    }
}

bool escaped()
{
    int i;
    for(i=0;i<5;i++)
    if(C[i]==0)
    return true;

    return false;
}
int main()
{
    int n,i,x,y,t=1;

    while(scanf("%d %d %d",&r,&c,&n) && n+c+r)
    {
        for(i=0;i<n;i++)
        scanf("%d %d",&a[i][0],&a[i][1]);
        scanf("%d %d",&x,&y);

        memset(C,0,sizeof(C));
        for(i=0;i<n;i++)
        {
            captured(a[i][0],a[i][1],x,y);

        }
        if(escaped())
        printf("Case %d: Escaped again! More 2D grid problems!\n",t++);
        else
        printf("Case %d: Party time! Let's find a restaurant!\n",t++);

    }
    return 0;
}
