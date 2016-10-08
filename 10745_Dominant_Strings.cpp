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

vector<string> s;
vector<vector<int> > c;
string str;
int i,j;
bool f[15010];

bool dominates(int i,int j)
{
    for(int k=0;k<26;k++)
        if(c[i][k]<c[j][k])
            return false;
    return true;
}

int main()
{

    memset(f,true,sizeof(f));
    while(cin>>str)
    {
        s.push_back(str);
    }
    sort(s.begin(),s.end());
    vector<int>m(26,0);
    for(i=0;i<s.size();i++)
    {
        vector<int>m(26,0);

        for(j=0;j<s[i].size();j++)
        {
            m[s[i][j]-'a']++;
        }
        c.push_back(m);
    }
    for(i=0;i<s.size();i++)
    {
        if(f[i])
        {
            for(j=i+1;j<s.size();j++)
            {
                if(dominates(i,j))
                f[j]=false;
                if(dominates(j,i))
                {
                    f[i]=false;
                    j=s.size();
                }

            }
        }
    }
    for(i=0;i<s.size();i++)
    {
        if(f[i])
        cout<<s[i]<<endl;
    }
    return 0;
}
