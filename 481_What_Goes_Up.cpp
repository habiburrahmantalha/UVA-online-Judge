//TLE
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int>v;



void LIS()
{
    vector<int>s,p(v.size(),0);
    int a,b,c,i;

    s.push_back(0);
    for(i=1;i<v.size();i++)
    {
        if(v[s.back()]<v[i])
        {
            p[i]=s.back();
            s.push_back(i);
            continue;
        }

        for(a=0,b=s.size()-1;a<b;)
        {
            c=(a+b)/2;
            if(v[s[c]]<v[i])
            a=c+1;
            else
            b=c;
        }

        if(v[i]>v[s[a]])
        {
            if(a>0)
            p[i]=s[a-1];

            s[a]=i;
        }
    }
    for(i=0;i<s.size();i++)
    printf()
}

int main()
{
    freopen("in.txt","r",stdin);
    int x;

    while(scanf("%d",&x)==1)
    {
        v.push_back(x);
    }
    LIS();

    return 0;
}
