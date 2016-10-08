#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
struct S
{
    int i,t;
};

int main()
{
    S x;
    queue<S>q;
    int n,k,i,j;
    while(scanf("%d %d",&n,&k)==2 && n+k)
    {
        for(i=0;i<n;i++)
        {
            x.i=i+1;
            x.t=0;
            q.push(x);
        }
        i=1,j=1;
        while(!q.empty())
        {
            x=q.front();q.pop();
            x.t+=i;
            if(x.t==40)
            {
                printf("%3d",x.i);
                j++;
                if(j>k)
                j=1;
                i=j;
            }
            if(x.t>40)
            {
                printf("%3d",x.i);
                i=x.t-40;

            }
            if(x.t<40)
            {
                j++;
                if(j>k)
                j=1;
                i=j;
                q.push(x);
            }
        }
        printf("\n");
    }
    return 0;
}
