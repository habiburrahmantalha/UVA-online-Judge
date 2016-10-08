//Problem Type :
//Time :    0.16
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
    int n,i,j;
    vector<pair<int,int> > v;
    while(scanf("%d",&n)==1)
    {


        for(i=n+1;i<=n*2;i++)
        {

            j=floor(i*n/(i-n));

            if(i*j==n*(i+j))
            {
                v.push_back(make_pair(j,i));
            }

        }
        printf("%d\n",v.size());
        for(i=0;i<v.size();i++)
        {
            printf("1/%d = 1/%d + 1/%d\n",n,v[i].first,v[i].second);
        }
        v.clear();
    }
    return 0;
}
