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
    int x,i,l;
    vector<int>v,a,b;
    int f[35];
    char c;
    while(scanf("%d",&x)==1)
    {
        v.push_back(x);
        f[x]=i=0;
        while(scanf("%d%c",&x,&c))
        {
            v.push_back(x);
            f[x]=++i;
            if(c=='\n')
            break;
        }
        l=v.size();
        a=v;
        sort(a.begin(),a.end());
        b=v;
        if(a[l-1]!=v[l-1])
        {
            printf("%d",l-f[a[l-1]]);
            reverse(a.begin(),a.begin()+f[a[l-1]]);
            b=a;
            sort(b.begin(),b.end());
        }

        if(a[0]!=)

    }
    return 0;
}
