#include<stdio.h>
#include<vector>
#include<iostream>
#include<map>
#include<queue>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

long long final,start;
int s;

long long next(long long x,int i,int j)
{
    char str[11];
    if(i==0)
    {
        sprintf(str+1,"%lld",x);
        str[0]='0';
    }
    else
    sprintf(str,"%lld",x);
    //cout<<str<<endl;
    if(i!=j)
    swap(str[i],str[j]);
    long long n=atol(str);
    return n;


}

bool D[876543219];
map<long long,string> move;
int X[9][4]={   0,0,1,3,
                -1,0,1,3,
                -1,0,0,3,
                0,-3,1,3,
                -1,-3,1,3,
                -1,-3,0,3,
                0,-3,1,0,
                -1,-3,1,0,
                -1,-3,0,0,
            };
char dir[]={"rdlu"};
void bfs()
{
    int i,j,k;

    long long v,u;
    string st;

    queue<long long> q;
    queue<int>p;



    q.push(start);
    p.push(s);
    move[s]="";

    D[start]=true;

    while(!q.empty())
    {
        u=q.front();q.pop();
        j=p.front();p.pop();
        //st=r.front();r.pop();

        for(i=0;i<4;i++)
        {
            if(X[j][i]!=0)
            {
                k=X[j][i]+j;

                v=next(u,j,k);

                if(!D[v])
                {
                    D[v]=true;
                    q.push(v);
                    p.push(k);
                    //if(move[v].size()==1)
                    {
                        //break;
                        //cout<<st+dir[i]<<endl;
                        //return;
                    }
                    move[v]=move[u];
                    move[v]+=dir[i];
                    //r.push(st+dir[i]);

                }
            }
        }
    }

}
int main()
{

    //freopen("in.txt","r",stdin);

    int i,tc,k,t=1;
    char x[2],y[11];


    final=123456780;
    memset(D,false,sizeof(D));
    start=final;
    s=8;
    bfs();
    scanf("%d",&tc);
    while(tc--)
    {
        for(i=0;i<9;i++)
        {
            scanf("%s",x);
            if(x[0]=='x')
            {
                s=i;
                x[0]='0';
            }
            y[i]=x[0];
        }
        y[i]=0;


        //cout<<start<<endl;
        string res=move[atol(y)];
        reverse(res.begin(),res.end());
        if(!D[atol(y)])
        cout << "unsolvable" << endl;
        else

        cout<<res<<endl;

        if(tc)
        printf("\n");

    }
    return 0;
}
