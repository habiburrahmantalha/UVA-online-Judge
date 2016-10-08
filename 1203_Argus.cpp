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


int main()
{
    string ins;
    int id,period,q;
    pair<int,int>curr_ins;
    int m[3010];
    priority_queue<pair<int,int> > pq;

    while(cin>>ins)
    {
        do
        {
            if(ins=="Register")
            {
                cin>>id>>period;
                m[id]=period;
                pq.push(make_pair(-period,-id));
            }

        }while(cin>>ins && ins!="#");

        scanf("%d",&q);
        while(q--)
        {
            curr_ins=pq.top();pq.pop();
            //cout<<-curr_ins.first<<" ";
            cout<<-curr_ins.second<<endl;
            curr_ins.first-=m[-curr_ins.second];

            pq.push(curr_ins);

        }
    }
    return 0;
}
