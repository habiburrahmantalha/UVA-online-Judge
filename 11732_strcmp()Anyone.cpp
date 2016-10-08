//Problem Type : addhoc
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


int n,c;
vector<string> x;
void index(vector<int> u,int k)
{
    vector<int> v;
    int i,j;
    c+=u.size()*(u.size()-1)/2;

    for(i=0;i<u.size();i++)
    {
        v.clear();
        v.push_back(u[i]);
        j=i+1;

        while(j<u.size() && k<x[u[i]].size() && k<x[u[j]].size() && x[u[i]][k]==x[u[j]][k])
        {
            v.push_back(u[j]);
            j++;
        }
        if(v.size()>1)
        index(v,k+1);
        i=j;
        i--;
    }
}

int main()
{
    int i,t=1;
    vector<int> v;
    string str;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            cin>>str;
            x.push_back(str);
        }
        sort(x.begin(),x.end());
        for(i=0;i<n;i++)
        v.push_back(i);

        c=0;
        index(v,0);
        printf("Case %d: %d\n",t++,c);
        //for(i=0;i<n;i++)
        //cout<<v[i]<<endl;

        x.clear();
        v.clear();
    }
    return 0;
}
