#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compdec(string a,string b)
{
   return a+b > b+a;
}
int main()
{
    vector<string> vs;
    string str;
    int n,i;

    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            cin>>str;
            vs.push_back(str);
        }
        sort(vs.begin(),vs.end(),compdec);
        for(i=0;i<n;i++)
            cout<<vs[i];
        cout<<endl;
        vs.clear();
    }
    return 0;
}
