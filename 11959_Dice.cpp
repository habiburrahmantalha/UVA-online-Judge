//Problem Type :    bfs
//Time :    .104
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

string a,b;

bool bfs()
{
    queue<string> q;
    map<string,int> visit;
    char top,bottom,left,right,front,back;
    int i;
    if(a==b)
    return true;
    string u,v;
    q.push(a);
    visit[a]=1;

    while(!q.empty())
    {
        u=q.front();q.pop();

        top=u[0];
        bottom=u[1];
        front=u[2];
        left=u[3];
        back=u[4];
        right=u[5];

        for(i=0;i<4;i++)
        {
            switch(i)
            {
                case 0:
                {
                    //west
                    v=back;
                    v+=front;
                    v+=top;
                    v+=left;
                    v+=bottom;
                    v+=right;

                    break;
                }
                case 1:
                {
                    //east
                    v=front;
                    v+=back;
                    v+=bottom;
                    v+=left;
                    v+=top;
                    v+=right;

                    break;

                }
                case 2:
                {
                    //north
                    v=right;
                    v+=left;
                    v+=front;
                    v+=top;
                    v+=back;
                    v+=bottom;

                    break;

                }
                case 3:
                {
                    //south
                    v=left;
                    v+=right;
                    v+=front;
                    v+=bottom;
                    v+=back;
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
        cin>>a>>b;
        if(bfs())
        printf("Equal\n");
        else
        printf("Not Equal\n");

    }
    return 0;
}
