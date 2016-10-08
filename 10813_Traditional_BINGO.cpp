#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int g[10][10],X[100],Y[100],n;

bool bingo()
{
    int i,j,H,V,D1,D2;
    for(i=0;i<5;i++)
    {
        H=V=0;
        for(j=0;j<5;j++)
        {
            H+=g[i][j];
            V+=g[j][i];
        }
        if(V==-5 || H==-5)
        return true;
    }
    D1=D2=0;
    for(i=0;i<5;i++)
    {
        D1+=g[i][i];
        D2+=g[i][4-i];
    }

    if(D1==-5 || D2==-5)
    return true;

    return false;


}
void print()
{
    int i,j;
    for(i=0;i<5;i++)
    {for(j=0;j<5;j++)

        printf("%d ",g[i][j]);
        printf("\n");
    }
}
int main()
{
    int tc,i,j,m;
    bool f;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(g,0,sizeof(g));
        memset(X,-1,sizeof(X));
        memset(Y,-1,sizeof(Y));
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(i==2 && j==2)
                continue;
                scanf("%d",&g[i][j]);
                X[g[i][j]]=i;
                Y[g[i][j]]=j;
            }
        }
        f=false;
        for(i=0;i<75;i++)
        {
            scanf("%d",&m);
            if(f)
            continue;
            if(X[m]==-1)
            g[2][2]=-1;
            else
            g[X[m]][Y[m]]=-1;

            if(bingo())
            {
                f=true;
                n=i;
            }
            //print();
        }
        printf("BINGO after %d numbers announced\n",n+1);
    }
    return 0;
}
