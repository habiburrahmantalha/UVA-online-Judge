#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

int g[201][201],n,v[210];
bool guard[210],impossible;


int bfs(int x,bool f)
{
    int y,c=0;
    queue<int>q;

    q.push(x);
    v[x]=1;
    guard[x]=f;
    if(f)
    c=1;
    while(!q.empty())
    {
        x=q.front();q.pop();
        for(y=0;y<n;y++)
        {
            if(g[x][y] && !v[y])
            {
                v[y]=1;
                q.push(y);
                if(guard[x])
                    guard[y]=false;
                else
                {
                    guard[y]=true;
                    c++;
                }

            }
            else if(g[x][y] && v[y] && x!=y)
            {
                if(guard[x]==guard[y])
                {
                    impossible=true;
                    //return;
                }

            }
        }
    }
    return c;
}
int main()
{

	int m,a,b,tc,i,res;
	vector<int>v1,v2;
	scanf("%d",&tc);
	while(tc--)
	{
		memset(g,0,sizeof(g));
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			g[a][b]=g[b][a]=1;
		}


		impossible=false;

		memset(v,0,sizeof(v));
		memset(guard,false,sizeof(guard));
        for(i=0;i<n;i++)
        {
            if(!v[i])
                v1.push_back(bfs(i,true));
        }

        memset(v,0,sizeof(v));
		memset(guard,false,sizeof(guard));
        for(i=0;i<n;i++)
        {
            if(!v[i])
                v2.push_back(bfs(i,false));
        }
        res=0;
        for(i=0;i<v1.size();i++)
        //cout<<v1[i]<<" "<<v2[i]<<endl;
        res+=max(1,min(v1[i],v2[i]));

		if(impossible)
		printf("-1\n");
		else
		printf("%d\n",res);

		v1.clear(),v2.clear();

	}
    return 0;
}


