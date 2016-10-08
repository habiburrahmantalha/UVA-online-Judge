//Problem Type :    bfs
//Time :    .008
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
        front=u[1];
        left=u[2];
        right=u[3];
        back=u[4];
        bottom=u[5];





        for(i=0;i<4;i++)
        {
            switch(i)
            {
                case 0:
                {
                    //west
                    v=back;
                    v+=top;
                    v+=left;
                    v+=right;
                    v+=bottom;
                    v+=front;

                    break;
                }
                case 1:
                {
                    //east
                    v=front;
                    v+=bottom;
                    v+=left;
                    v+=right;
                    v+=top;
                    v+=back;

                    break;

                }
                case 2:
                {
                    //north
                    v=right;
                    v+=front;
                    v+=top;
                    v+=bottom;
                    v+=back;
                    v+=left;

                    break;

                }
                case 3:
                {
                    //south
                    v=left;
                    v+=back;
                    v+=top;
                    v+=bottom;
                    v+=front;
                    v+=right;

                    break;

                }
                /*
                case 4:
                {
                    //south
                    v=top;
                    v+=left;
                    v+=back;
                    v+=front;
                    v+=right;
                    v+=bottom;

                    break;

                }
                */

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
    string str;
    while(cin>>str)
    {
        a=str.substr(0,6);
        b=str.substr(6,12);
        //cout<<a<<" "<<b<<endl;
        if(bfs())
        printf("TRUE\n");
        else
        printf("FALSE\n");

    }
    return 0;
}

