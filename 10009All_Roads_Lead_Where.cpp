//idea not clear

#include<stdio.h>
#include<queue>
#include<map>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        memset(g,false,sizeof(g));
        cin>>N>>M;
        n=0;
        for(i=0;i<N;i++)
        {
            cin>>city1>>city2;

            if(!city[city1])
            city[city1]=n++;
            if(!city[city2])
            city[city2]=n++;

            g[city[city1]][city[city2]]=g[city[city2]][city[city1]]=true;
        }
        bfs()
        for(i=0;i<M;i++)
        {

        }
    }
}
