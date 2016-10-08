#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string>p;
int n;
bool consistent_list()
{
    string temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        if(p[i].size()<p[i+1].size())
        {
            temp=p[i+1].substr(0,p[i].size());
            if(temp==p[i])
            return false;
        }

    }
    return true;
}

int main()
{
    string str;

    int tc,i;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>str;
            p.push_back(str);
        }
        sort(p.begin(),p.end());

        //for(i=0;i<p.size();i++)
            //cout<<p[i]<<endl;

        if(consistent_list())
            printf("YES\n");
        else
            printf("NO\n");
        p.clear();
    }
    return 0;
}
