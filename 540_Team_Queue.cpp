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
int team[1000000],in_queue[1010];

struct T
{
    queue<int> q;
};
T Q[2010];

int main()
{

    int n,m,x,i,j,t=1,top,current;
    string op;
    while(scanf("%d",&n)==1 && n)
    {
        for(i=0;i<2010;i++)
        {
            while(!Q[i].q.empty())
                Q[i].q.pop();
        }
        memset(in_queue,0,sizeof(in_queue));

        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&x);
                team[x]=i;
            }
        }
        printf("Scenario #%d\n",t++);
        top=current=1;
        while(cin>>op)
        {
            if(op=="STOP")
            break;
            else if(op=="ENQUEUE")
            {
                scanf("%d",&x);

                if(!in_queue[team[x]])
                {
                    in_queue[team[x]]=current;
                    Q[current].q.push(x);
                    current++;

                }
                else
                    Q[in_queue[team[x]]].q.push(x);
            }
            else if(op=="DEQUEUE")
            {
                x=Q[top].q.front();
                Q[top].q.pop();
                if(Q[top].q.empty())
                {
                    in_queue[team[x]]=0;
                    top++;
                }
                printf("%d\n",x);

            }
        }
        printf("\n");
    }
    return 0;
}
