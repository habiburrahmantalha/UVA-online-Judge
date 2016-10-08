//Problem Type : backtracking,permutation
//Time :    0.116
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
    string line,s,mxs,mns;
    int i,j,x,g[30][30],f[30],mx,mn;
    while(getline(cin,line))
    {
        memset(g,0,sizeof(g));
        memset(f,0,sizeof(f));
        if(line=="#")
        break;
        s.clear();
        for(i=0;i<line.size();i++)
        {
            if(isalpha(line[i]) && f[line[i]-'A']==0)
            {
                f[line[i]-'A']=1;
                s+=line[i];
            }
        }
        sort(s.begin(),s.end());
        //cout<<s<<endl;
        for(i=0;i<line.size();i++)
        {
            switch(line[i])
            {
                case ':':
                {
                    for(i=i+1;line[i]!=';' && i<line.size();i++)
                    g[x][line[i]-'A']=1;
                    break;
                }
                default :
                {
                    x=line[i]-'A';
                    break;
                }
            }
        }
        mn=10;
        do
        {
            mx=0;
            for(i=0;i<s.size();i++)
            {
                for(j=0;j<s.size();j++)
                {
                    if(g[s[i]-'A'][s[j]-'A'])
                    {
                        if(mx<abs(i-j))
                        {
                            mx=abs(i-j);
                        }
                    }
                }
            }
            if(mx<mn)
            {
                mn=mx;
                mns=s;
            }
        }while(next_permutation(s.begin(),s.end()));
        for(i=0;i<mns.size();i++)
        printf("%c ",mns[i]);
        printf("-> %d\n",mn);
    }
    return 0;
}
