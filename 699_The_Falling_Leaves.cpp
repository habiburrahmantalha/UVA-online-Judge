#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
map<int,int>leaf;
map<int,int>:: iterator it;

void insert(int k)
{
    int x;
    scanf("%d",&x);

    if(x==-1)
    return;

    leaf[k]+=x;

    insert(k-1);
    insert(k+1);
}
int main()
{
    int x,t=1;

    while(scanf("%d",&x) && x!=-1)
    {
        leaf.clear();

        leaf[0]=x;
        insert(-1);
        insert(1);

        printf("Case %d:\n",t++);
        it=leaf.begin();
        cout<<it->second;
        for(it++;it!=leaf.end();it++)
        cout<<" "<<it->second;
        cout<<endl<<endl;
    }
    return 0;
}
