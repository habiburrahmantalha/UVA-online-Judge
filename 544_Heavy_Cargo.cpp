#include<stdio.h>
#include<map>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int n,g[201][201];

void warshal()
{
    int i,j,k;

    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            if(g[i][k]!=0)
            for(j=1;j<=n;j++)
            {
                if(g[k][j]!=0)
                g[i][j]=max(g[i][j],min(g[i][k],g[k][j]));
            }
        }
    }
}

int main()
{
    int m,i,load,city,tc=1;
    string city1,city2;
    map<string,int> mp;
    while(scanf("%d %d",&n,&m) && n&& m)
    {
        city=1;
        memset(g,0,sizeof(g));
        for(i=0;i<m;i++)
        {
            cin>>city1>>city2>>load;
            if(!mp[city1])
                mp[city1]=city++;
            if(!mp[city2])
                mp[city2]=city++;
            g[mp[city1]][mp[city2]]=load;
            g[mp[city2]][mp[city1]]=load;
        }
        cin>>city1>>city2;
        warshal();
        cout<<"Scenario #"<<tc++<<endl;
        cout<<g[mp[city1]][mp[city2]];
        cout<<" tons"<<endl<<endl;
    }
    return 0;
}
