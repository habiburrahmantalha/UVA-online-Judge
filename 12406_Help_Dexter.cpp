#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define LL long long
vector<LL>v[20];

LL POW(int x)
{
    LL y=1;
    while(x--)
    y*=10;

    return y;
}
void precal()
{
    int i,j;
    LL x,y;
    v[1].push_back(2);
    for(i=2;i<18;i++)
    {
        for(j=0;j<v[i-1].size();j++)
        {
            x=POW(i-1);
            y=x+v[i-1][j];
            v[i].push_back(y);
            y=x*2+v[i-1][j];
            v[i].push_back(y);
        }
        sort(v[i].begin(),v[i].end());
    }

}
int main()
{
    precal();
    int tc,t=1,i;
    LL p,q,x,y,d;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&p,&q);
        d=1;
        for(i=0;i<q;i++)
        d<<=1;
        x=y=-1;
        for(i=0;i<v[p].size();i++)
        if(v[p][i]%d==0)
        {
            x=v[p][i];
            break;
        }
        for(i=v[p].size()-1;i>=0;i--)
        if(v[p][i]%d==0)
        {
            y=v[p][i];
            break;
        }
        if(x<0 && y<0)
        printf("Case %d: impossible\n",t++);
        else if(x==y)
        printf("Case %d: %lld\n",t++,x);
        else
        printf("Case %d: %lld %lld\n",t++,x,y);

    }
    return 0;
}
