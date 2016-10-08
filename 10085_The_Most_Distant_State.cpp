#include<stdio.h>
#include<vector>
#include<iostream>
#include<map>
#include<queue>
#include<string.h>
using namespace std;

vector<int>final,start;
int s,f;
long long to_int(vector<int> v)
{
    long long i,j,k,n=0;
    for(i=0,j=9;i<9;i++,j--)
    {
        for(k=1;k<j;k++)
        v[i]*=10;

        n+=v[i];
    }
    return n%200000000;


}

bool D[200000001];
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
char dir[]={"LURD"};
void bfs()
{
    int i,j,k,cost;
    vector<int>v,u;
    queue<vector<int> > q;
    queue<int>p;
    queue<string> r;
    string st;

    q.push(start);
    p.push(s);
    r.push("");

    D[to_int(start)]=true;

    while(!q.empty())
    {
        u=q.front();q.pop();
        j=p.front();p.pop();
        st=r.front();r.pop();

        for(i=0;i<4;i++)
        {
            if(X[j][i]!=0)
            {
                k=X[j][i]+j;

                v=u;
                swap(v[k],v[j]);

                if(!D[to_int(v)])
                {
                    D[to_int(v)]=true;
                    q.push(v);
                    p.push(k);

                    r.push(st+dir[i]);

                }
            }
        }
    }

    for(i=1;i<=9;i++)
    {
        if(i%3==0)
        printf("%d\n",u[i-1]);
        else
        printf("%d ",u[i-1]);

    }
    cout<<st<<endl;
    //cout<<st<<st.size()<<endl;

}
int main()
{

    //freopen("in.txt","r",stdin);
    int i,tc,x,k,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        for(i=0;i<9;i++)
        {
            scanf("%d",&x);
            if(x==0)
                s=i;
            start.push_back(x);
        }
        memset(D,false,sizeof(D));
        printf("Puzzle #%d\n",t++);
        bfs();
        printf("\n");

        start.clear();
        final.clear();

    }
    return 0;
}
