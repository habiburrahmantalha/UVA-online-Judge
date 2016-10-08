#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;


int cards(set<int> s,bool t[100010])
{
    set<int>::iterator it;
    int c=0;
    for(it=s.begin();it!=s.end();it++)
    {
        if(!t[*it])
        {
            //cout<<*it<<endl;
            c++;
        }
    }
    return c;
}
int main()
{
    int x,y,z,i;
    set<int>Xs,Ys;
    bool X[100010],Y[100010];
    while(scanf("%d %d",&x,&y)==2 && x+y)
    {
        Xs.clear();
        Ys.clear();
        memset(X,false,sizeof(X));
        memset(Y,false,sizeof(Y));
        for(i=0;i<x;i++)
        {
            scanf("%d",&z);
            X[z]=true;
            Xs.insert(z);
        }
        for(i=0;i<y;i++)
        {
            scanf("%d",&z);
            Y[z]=true;
            Ys.insert(z);
        }
        if(Xs.size()<Ys.size())
            printf("%d\n",cards(Xs,Y));
        else
            printf("%d\n",cards(Ys,X));
    }

    return 0;
}
