//Problem Type : adhoc,substring fr
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
    int tc,i,j,l,mx,mxs;
    map<string,int>m;
    map<string,int> :: iterator it;
    scanf("%d",&tc);
    string s,temp;
    while(tc--)
    {
        cin>>s;
        l=s.size();
        for(i=0;i<l;i++)
        {
            for(j=1;i+j<=l;j++)
            {
                temp=s.substr(i,j);
                m[temp]++;
                //cout<<temp<<endl;
            }
        }
        mx=mxs=0;
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->second>=2)
            {
                if(it->first.size() > mxs)
                {
                    mxs=it->first.size();
                    temp=it->first;
                    mx=it->second;
                }
                else if(it->first.size() == mxs)
                {
                    if(it->second > mx)
                    {
                        temp=it->first;
                        mx=it->second;
                    }

                }
            }
        }

        if(mx>=2)
        cout<<temp<<" "<<mx<<endl;
        else
        cout<<"No repetitions found!"<<endl;

        m.clear();
    }
    return 0;
}
