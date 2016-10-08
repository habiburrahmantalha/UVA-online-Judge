//Problem Type :
//Time :
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
using namespace std;
#define PI 2 * acos (0.0)

map<vector<string>,bool>V;
int X[]={2,2,1,1,-1,-1,-2,-2};
int Y[]={-1,1,-2,2,-2,2,-1,1};

void FEN(vector<string> G,int k,int x,int y)
{
    for(i=0;i<8;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v))
        {
            SWAP(x,y,u,v);
            if(!V[G])
        }
    }
}

int main()
{
    scanf("%d\n",&tc);
    while(tc--)
    {
        vector<string>G;
        for(i=0;i<5;i++)
        {
            gets(s);
            G.push_back(s);
        }
    }
    return 0;
}
