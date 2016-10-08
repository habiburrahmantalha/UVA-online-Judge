//TLE
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<queue>
#include<iostream>
#include<vector>
using namespace std;

string s,e;
vector<string>forbidden;
map<string,int> visit;
vector<string>::iterator it;

bool find(string x)
{
    for ( it=forbidden.begin() ; it < forbidden.end(); it++ )
    if(*it==x)
    {

        return false;
    }
    return true;
}
string odd(string x,int i)
{
    int a;
    a=x[i]-48;
    a++;
    if(a>9)
    a=0;
    x[i]=a+48;
    return x;
}

string even(string x,int i)
{
    int a;
    a=x[i]-48;
    a--;
    if(a<0)
    a=9;
    x[i]=a+48;
    return x;
}

int bfs ()
{
    map<string,int> d;

    queue<string> q;
    string u,v;
    int i,j;

    q.push(s);
    forbidden.push_back(s);
    d[s]=0;
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            for(j=0;j<2;j++)
            {
                if(j==0)
                v=odd(u,i);
                else
                v=even(u,i);

                //cout<<v<<endl;
                //if(find(v)==true)
                if(!visit[v])
                {
                    d[v]=d[u]+1;
                    //forbidden.push_back(v);
                    visit[v]=true;
                    //cout<<v<<" "<<e<<endl;
                    if(v==e)
                    return d[v];

                    q.push(v);

                }
            }
        }
    }
    return -1;
}

int main()
{

    string x;
    char a,b,c,d;
    int tc,f,i;
    scanf("%d",&tc);
    while(tc--)
    {
        forbidden.clear();
        cin>>a>>b>>c>>d;
        s=a;
        s+=b;
        s+=c;
        s+=d;
        cin>>a>>b>>c>>d;
        e=a;
        e+=b;
        e+=c;
        e+=d;

        scanf("%d",&f);
        for(i=0;i<f;i++)
        {
            cin>>a>>b>>c>>d;
            x=a;
            x+=b;
            x+=c;
            x+=d;
            //forbidden.push_back(x);
            visit[x]=true;

        }

        printf("%d\n",bfs());
    }
    return 0;
}
