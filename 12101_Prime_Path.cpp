#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int d[10001],vi[10001],a,b;
bool prime[10001];

void sieve ()
{
    int i,j,N=10000;
    memset (prime, true, sizeof (prime));
    prime [0] = prime [1] = false;

    for (i = 4; i < N; i += 2 )
        prime [i] = false;

    for (i = 3; i * i <= N; i++ )
    {
        if ( prime [i] )
        {
            for (j = i * i; j < N; j += 2 * i )
                prime [j] = false;
        }
    }
}
int get_int(char x[10])
{
   int y=(x[0]-'0')*1000;
   y+=(x[1]-'0')*100;
   y+=(x[2]-'0')*10;
   y+=(x[3]-'0');
   return y;
}


void bfs()
{
    queue<int>q;

    char x[10],y[10];
    int i,j,z,u,v;

    q.push(a);
    d[a]=0;
    vi[a]=1;

    while(!q.empty())
    {
        u=q.front();q.pop();
        z=u;
        i=3;
        while(z)
        {
            x[i]=(z%10)+'0';
            z/=10;
            i--;
        }

        for(i=0;i<4;i++)
        {
            for(j=0;j<10;j++)
            {
                strcpy(y,x);
                y[i]=j+'0';
                v=get_int(y);
                //printf("%s->",y);

                if(prime[v] && vi[v]==0 && v>1000)
                {
                    d[v]=d[u]+1;
                    vi[v]=1;
                    q.push(v);
                }
            }
        }
    }

}
int main()
{
    int tc;

    sieve();

    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d %d",&a,&b);


        memset(vi,0,sizeof(vi));
        memset(d,0,sizeof(d));

        if(a!=b)
        bfs();
        printf("%d\n",d[b]);
    }
    return 0;
}
