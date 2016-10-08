#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int X[]={0,-1,-1,-1,0,1,1,1};
int Y[]={-1,-1,0,1,1,1,0,-1};
char g[55][55];
char s[55];
int n,m;

bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
    return false;

    return true;
}



bool find(int x,int y,int k,int l)
{
    for(int i=1;i<l;i++)
    {
        x=x+X[k];
        y=y+Y[k];
        if(!valid(x,y) || g[x][y]!=s[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int tc,i,j,k,w;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",g[i]);
            for(j=0;j<m;j++)
            g[i][j]=tolower(g[i][j]);
        }

        scanf("%d",&w);
        while(w--)
        {
            scanf("%s",s);
            for(i=0;i<strlen(s);i++)
            s[i]=tolower(s[i]);

            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                if(g[i][j]==s[0])
                {

                    for(k=0;k<8;k++)
                    {
                        if(find(i,j,k,strlen(s)))
                        {
                            printf("%d %d\n",i+1,j+1);
                            i=n;
                            j=m;
                            break;
                        }
                    }
                }
            }


        }
        if(tc!=0)
            printf("\n");
    }
    return 0;
}
