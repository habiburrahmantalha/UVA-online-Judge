//Problem Type : string matching,addhoc
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
map<string,int> m;
vector<string> v;

bool compound(int i)
{
    int j;
    for(j=0;j<v[i].size();j++)
    {
        if(m[v[i].substr(0,j)])
            if(m[v[i].substr(j,v[i].size()-j)])
                return true;
    }
    return false;
}
int main()
{
    char s[20];
    int i;
    bool f[120010];
    memset(f,false,sizeof(f));
    while(scanf("%s",s)==1)
    {
        m[s]=1;
        v.push_back(s);
    }
    for(i=0;i<v.size();i++)
    {
        if(compound(i))
        f[i]=true;
    }
    for(i=0;i<v.size();i++)
        if(f[i])
            printf("%s\n",v[i].c_str());
    return 0;
}
