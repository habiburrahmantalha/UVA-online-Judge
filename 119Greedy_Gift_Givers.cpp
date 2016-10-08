#include<iostream>
#include<map>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    string str[20],name;
    int n,p,i,money,given;
    bool f=false;

    while(scanf("%d",&n)==1)
    {
        if(f)
        cout<<endl;
        map<string,int>m;
        for(i=0;i<n;i++)
        {
            cin>>str[i];
            m[str[i]]=0;
        }

        for(i=0;i<n;i++)
        {
            cin >>name>>money>>p;

            //m[name]=money;

            if(p>0)
            {
                given=floor(money/p);
                m[name]-=given*p;
            }

            while(p--)
            {
                cin>>name;
                m[name]+=given;
            }

        }
        for(i=0;i<n;i++)
        {
            cout<<str[i]<<" "<<m[str[i]]<<endl;
        }
        f=true;
    }
    return 0;
}
