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

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.first>b.first;
}

int main()
{
    int tc,i,j,k,x,p,n,t;
    vector<pair<int,int> > v;
    queue<pair<int,int> > s;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&p);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            v.push_back(make_pair(x,i));
            s.push(make_pair(x,i));
        }
        sort(v.begin(),v.end(),cmp);
        t=0;
        i=0;
        while(1)
        {
            x=s.front().first;
            k=s.front().second;
            s.pop();
            if(x==v[i].first)
            {
                //cout<<"1"<<endl;
                t++;
                i++;
                if(p==k)
                break;
            }
            else
            {
                //cout<<"2"<<endl;
                s.push(make_pair(x,k));
            }
        }
        printf("%d\n",t);
        v.clear();
        while(!s.empty())
            s.pop();
    }
    return 0;
}
