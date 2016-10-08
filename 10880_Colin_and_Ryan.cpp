//Problem Type :
//Time :
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


int main()
{
    int C,R,N,i,j,t=1,tc;
    vector<int>v;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&C,&R);
        if(C==R)
        {
            printf("Case #%d: 0\n",t++);
            continue;
        }
        N=C-R;
        for(i=1;i*i<=N;i++)
        {
            if(N%i==0)
            {
                if(i>R)
                v.push_back(i);
                j=N/i;
                if(j>R && i!=j)
                v.push_back(j);
            }

        }
        sort(v.begin(),v.end());
        printf("Case #%d:",t++);
        for(i=0;i<v.size();i++)
        printf(" %d",v[i]);
        printf("\n");
        v.clear();
    }
    return 0;
}
