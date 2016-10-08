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

char w[50],s[50],M[130][20][50],N[130][20][50];

void clears()
{
    int i,j,a,b;

    for(i=0;w[i];i++)
        for(j=0;j<17;j++)
        {
            strcpy(N[w[i]][j],M[w[i]][j]);
            //cout<<N[w[i]][j]<<endl;
        }


    for(i=0;s[i];i++)
    {
        for(j=0;s[j];j++)
        {
            if(s[i]!=s[j])
            {
                for(a=0;a<16;a++)
                {
                    for(b=0;b<44;b++)
                    {
                        if(N[s[i]][a][b]==M[s[j]][a][b])
                            N[s[i]][a][b]='.';
                    }
                }
            }

        }

    }

}

bool finds(int k)
{
    int i,j;
    for(i=0;i<16;i++)
    {
        for(j=0;j<44;j++)
        {
            if(N[s[k]][i][j]=='*')
                return true;
        }
    }
    return false;
}
int main()
{
    int n,q,i,j;

    scanf("%d %d",&n,&q);
    scanf("%s",w);

    for(i=0;w[i];i++)
        for(j=0;j<17;j++)
            scanf("%s",M[w[i]][j]);

    int Q=1;
    while(q--)
    {
        scanf("%s",s);
        clears();
        printf("Query %d: ",Q++);
        for(i=0;s[i];i++)
        {
            if(finds(i))
            printf("Y");
            else
            printf("N");
        }
        printf("\n");

    }
    return 0;
}
