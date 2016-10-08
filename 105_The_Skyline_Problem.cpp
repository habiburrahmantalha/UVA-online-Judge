//Problem Type : addhoc
//Time : 0.024
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
    int x,y,h,i,mx,f[10010]={0},j,mn;
    vector<int>v;
    mx=0;
    mn=10010;
    while(scanf("%d %d %d",&x,&h,&y)==3)
    {
        for(i=x;i<y;i++)
        f[i]=max(f[i],h);
        mx=max(max(x,y),mx);
        mn=min(min(x,y),mn);
    }
    for(i=mn;i<=mx;i++)
    {
        //printf("%d ",f[i]);
        v.push_back(i);
        v.push_back(f[i]);
        //printf("%d %d\n",i,f[i]);
        for(j=i;f[j]==f[i] && j<=mx;j++)
        continue;
        i=j;
        i--;
    }
    for(i=0;i<v.size()-1;i++)
    printf("%d ",v[i]);
    printf("%d\n",v[i]);

    v.clear();
    return 0;
}
