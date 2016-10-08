#include<cstdio>
#include<string>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    map <string,int> m;
    map <string,int> ::iterator it;
    string country,woman;
    int tc,i;

    while(scanf("%d",&tc)==1)
    {
        while(tc--)
        {
            cin>>country;
            getline(cin,woman);
            m[country]++;
        }

        for(it=m.begin();it!=m.end();it++)
        cout<<(*it).first<<" "<<(*it).second<<endl;

    }
    return 0;
}
