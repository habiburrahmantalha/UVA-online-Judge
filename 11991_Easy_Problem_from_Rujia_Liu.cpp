#include<vector>
#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;

int main()
{

    int x,y,i,n,q;
    while(scanf("%d %d",&n,&q)==2)
    {
        map< int, vector < int > >N;
        map<int,vector <int> >::iterator it;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            N[x].push_back(i+1);
        }
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&y,&x);
            it=N.find(x);
            if((*it).second.size()< y)
                printf("0\n");
            else
                printf("%d\n",(*it).second[y-1]);
        }
    }
    return 0;
}
