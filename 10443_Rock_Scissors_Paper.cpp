#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
char g[110][110],h[110][110];
int n,r,c;
map<char,char>mp;
bool valid(int x,int y)
{
    if(x<0 || x>=r || y<0 || y>=c)
    return false;

    return true;
}
void war()
{
    mp['R']='S';
    mp['S']='P';
    mp['P']='R';
    int i,j,k,x,y;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(h[i][j]=='.')
            h[i][j]=g[i][j];
            for(k=0;k<4;k++)
            {
                x=i+X[k];
                y=j+Y[k];
                if(valid(x,y) && g[x][y]==mp[g[i][j]])
                h[x][y]=g[i][j];
            }
        }
    }
}
void copy()
{
    int i,j;
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    g[i][j]=h[i][j];
}
int main()
{
    int tc,i;

    scanf("%d",&tc);
    while(tc--)
    {

        scanf("%d %d %d",&r,&c,&n);
        for(i=0;i<r;i++)
        scanf("%s",g[i]);

        for(i=0;i<n;i++)
        {
            memset(h,'.',sizeof(h));
            war();
            copy();
        }

        for(i=0;i<r;i++)
        printf("%s\n",g[i]);

        if(tc)
        printf("\n");
    }
    return 0;
}
