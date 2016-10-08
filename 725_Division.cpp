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

bool alldigit(int x,int y)
{
    bool f[10];
    memset(f,false,sizeof(f));
    while(x)
    {
        f[x%10]=true;
        x/=10;
    }
    if(y<10000)
    y*=10;
    while(y)
    {
        f[y%10]=true;
        y/=10;
    }
    for(int i=0;i<=9;i++)
        if(!f[i])
            return false;

    return true;
}

int main()
{
    int x,i,y;
    vector<pair<int,int> > v;
    bool f=false;
    while(scanf("%d",&x) && x)
    {
        if(f)
        printf("\n");
        for(i=10000;i<100000;i++)
        {
            if(i%x==0 && (y=i/x)>=1000)
            {
                //cout<<y<<i<<endl;
                if(alldigit(i,y))
                v.push_back(make_pair(i,y));
            }
        }
        if(v.size()==0)
        printf("There are no solutions for %d.\n",x);
        else
        {
            for(i=0;i<v.size();i++)
            {
                if(v[i].second<10000)
                printf("%d / 0%d = %d\n",v[i].first,v[i].second,x);
                else
                printf("%d / %d = %d\n",v[i].first,v[i].second,x);
            }
        }
        v.clear();
        f=true;
    }
    return 0;
}
