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
#include<sstream>
using namespace std;


int main()
{
    string s,b[100010],c[100010];
    stringstream ss;
    int tc,a[100010],n,i;

    scanf("%d",&tc);
    getline(cin,s);

    while(tc--)
    {
        getline(cin,s);

        getline(cin,s);
        ss<<s;
        n=0;
        while(ss>>a[n])
        {
            n++;
        }

        for(i=0;i<n;i++)
            cin>>b[i];
        getline(cin,s);
        for(i=0;i<n;i++)
            c[a[i]]=b[i];
        for(i=1;i<=n;i++)
            cout<<c[i]<<endl;
        if(tc)
            printf("\n");
        ss.clear();

    }
    return 0;
}
