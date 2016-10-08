#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int>N;
int n;

int POW(int j)
{
    int p=1,i;
    for(i=1;i<=j;i++)
    p*=2;

    return p;
}
void todec()
{
    int i;
    reverse(N.begin(),N.end());
    n=0;
    for(i=0;i<N.size();i++)
        n+=POW(i)*N[i];
}

int main()
{
    string s;
    int flag,i;
    while(cin>>s)
    {
        if(s=="~")
        break;
        N.clear();
        while(s!="#")
        {
            //cout<<s;
            if(s.size()==1)
            flag=1;
            else if(s.size()==2)
            flag=0;
            else
            for(i=2;i<s.size();i++)
            N.push_back(flag);

            cin>>s;
        }
        //for(i=0;i<N.size();i++)
        //cout<<N[i];
        todec();
        printf("%d\n",n);
    }
    return 0;
}
