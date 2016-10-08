#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

map<string,int> d,visit;
map<string,string> res;

void bfs(string s)
{
    queue<string> q;
    string u,v;
    char temp;
    int i;


    q.push(s);
    d[s]=1;
    visit[s]=1;
    res[s]="";

    while(!q.empty())
    {
        u=q.front();
        q.pop();



        //H3
        v=u;
        temp =v[6];
        v[6]=v[7];
        v[7]=v[8];
        v[8]=temp;
        if(d[v]==0)
        {
            //visit[v]=1;
            d[v]=d[u]+1;
            res[v]=res[u];
            res[v]+="3H";
            q.push(v);
        }

        //H2
        v=u;
        temp =v[3];
        v[3]=v[4];
        v[4]=v[5];
        v[5]=temp;
        if(d[v]==0)
        {
            //visit[v]=1;
            d[v]=d[u]+1;
            res[v]=res[u];
            res[v]+="2H";
            q.push(v);
        }

        //H1
        v=u;
        temp =v[0];
        v[0]=v[1];
        v[1]=v[2];
        v[2]=temp;

        if(d[v]==0)
        {
            //visit[v]=1;
            d[v]=d[u]+1;
            res[v]=res[u];
            res[v]+="1H";
            q.push(v);
        }
        //H3
        v=u;
        temp =v[8];
        v[8]=v[5];
        v[5]=v[2];
        v[2]=temp;
        if(d[v]==0)
        {
            //visit[v]=1;
            d[v]=d[u]+1;
            res[v]=res[u];
            res[v]+="3V";
            q.push(v);
        }

        //H2
        v=u;
        temp =v[7];
        v[7]=v[4];
        v[4]=v[1];
        v[1]=temp;
        if(d[v]==0)
        {
            //visit[v]=1;
            d[v]=d[u]+1;
            res[v]=res[u];
            res[v]+="2V";
            q.push(v);
        }


        //V1
        v=u;
        temp =v[6];
        v[6]=v[3];
        v[3]=v[0];
        v[0]=temp;
        if(d[v]==0)
        {
            //visit[v]=1;
            d[v]=d[u]+1;
            res[v]=res[u];
            res[v]+="1V";
            q.push(v);
        }


    }
}
int main()
{
    int x,i,j;

    string a;
    bfs("123456789");

    while(scanf("%d",&x)==1 && x)
    {
        a=x+'0';
        for(i=0;i<8;i++)
        {

            scanf("%d",&x);
            a+=x+'0';



        }
        //cout<<a<<endl;
        if(d[a])
        {
            printf("%d ",d[a]-1);
            for(i=res[a].size()-1;i>=0;i--)
            printf("%c",res[a][i]);
            printf("\n");
        }
        else
        printf("Not solvable\n");



    }
    return 0;
}
