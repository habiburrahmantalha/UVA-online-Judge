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

vector<string>G;
vector<pair<int,pair<int,int> > >Q;

int rock(int x,int y)
{
    int c=0,i;
    if(G[x][y]=='#')
    c++;
    for(i=x;i<15;i++)
    if(G[i][y]=='#')
    {
        c++;
        break;
    }
    for(i=x;i>=0;i--)
    if(G[i][y]=='#')
    {
        c++;
        break;
    }
    for(i=y;i<15;i++)
    if(G[x][i]=='#')
    {
        c++;
        break;
    }
    for(i=y;i>=0;i--)
    if(G[x][i]=='#')
    {
        c++;
        break;
    }

    return c;

}

bool cmp(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b)
{
    return a.first>b.first;
}
int main()
{
    string str;
    int i,j,c;

    while(cin>>str && str!="END")
    {
        G.push_back(str);
        for(i=1;i<15;i++)
        {
            cin>>str;
            G.push_back(str);
        }

        for(i=0;i<15;i++)
        {
            for(j=0;j<15;j++)
            {
                c=rock(i,j);
                Q.push_back(make_pair(c,make_pair(i,j)));
            }
        }
        sort(Q.begin(),Q.end(),cmp);
        for(i=0;i<Q.size();i++)
        {

            x=Q[i].second.first;
            y=Q[i].second.second;
            if(V[x][y])


        }

    }
    return 0;
}
