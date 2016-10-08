//Problem Type :    bfs
//Time :    .024
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

int a,b;

bool bfs()
{
    queue<int> q;
    map<int,int> visit;

    int top,bottom,left,right,front,back;
    int i;
    if(a==b)
    return true;
    int u,v;
    q.push(a);
    visit[a]=1;

    while(!q.empty())
    {
        u=q.front();q.pop();

        right=u%10;u/=10;
        back=u%10;u/=10;
        left=u%10;u/=10;
        front=u%10;u/=10;
        bottom=u%10;u/=10;
        top=u%10;u/=10;

        for(i=0;i<4;i++)
        {
            switch(i)
            {
                case 0:
                {
                    //west
                    v=back*100000;
                    v+=front*10000;
                    v+=top*1000;
                    v+=left*100;
                    v+=bottom*10;
                    v+=right;

                    break;
                }
                case 1:
                {
                    //east
                    v=front*100000;
                    v+=back*10000;
                    v+=bottom*1000;
                    v+=left*100;
                    v+=top*10;
                    v+=right;

                    break;

                }
                case 2:
                {
                    //north
                    v=right*100000;
                    v+=left*10000;
                    v+=front*1000;
                    v+=top*100;
                    v+=back*10;
                    v+=bottom;

                    break;

                }
                case 3:
                {
                    //south
                    v=left*100000;
                    v+=right*10000;
                    v+=front*1000;
                    v+=bottom*100;
                    v+=back*10;
                    v+=top;

                    break;

                }
            }

            if(!visit[v])
            {
                //cout<<v<<endl;
                visit[v]=1;
                q.push(v);
                if(v==b)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&a,&b);
        if(bfs())
        printf("Equal\n");
        else
        printf("Not Equal\n");

    }
    return 0;
}
