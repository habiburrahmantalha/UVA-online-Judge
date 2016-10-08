//Problem Type : adhoc ;time:P
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

struct lamp
{
    int x,i;
    lamp(int x, int i) : x(x), i(i){}
    bool operator < (const lamp &that) const
    {
        return x < that.x;
    }
};
bool cmp(int a,int b)
{
    return a>b;
}
int tc,i,j,n,m,row[1010],column[1010],T[1010][1010],sum,x;

int main()
{
    priority_queue<lamp> pqr,pqc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            pqr.push(lamp(x,i));
        }


        for(i=0;i<m;i++)
        {
            scanf("%d",&x);
            pqc.push(lamp(x,i));
        }


        memset(T,0,sizeof(T));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(row[i] && column[j])
                {
                    T[i][j]++;
                    row[i]--;
                    column[j]--;
                }

            }
        }

        sum=0;
        for(i=0;i<n;i++)
        sum+=row[i];
        for(i=0;i<m;i++)
        sum+=column[i];
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                sum+=T[i][j];
        printf("%d\n",sum);

    }
    return 0;
}
