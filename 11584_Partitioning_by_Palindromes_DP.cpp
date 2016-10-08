#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
char s[1010];
int l,v[1010];
//int g[1010][1010];
vector<int>g[1010];
void initialize()
{
    //memset(g,0,sizeof(g));
    int i,a,b;
    for(i=1;i<l;i++)
    {
        g[i].push_back(i);
        a=i-1;
        b=i+1;
        while(s[a]==s[b])
        {
            g[b].push_back(a);
            a--;
            b++;
        }
        a=i;
        b=i+1;
        while(s[a]==s[b])
        {
            g[b].push_back(a);
            a--;
            b++;
        }
    }
}
int main()
{
    int tc,mn,i,j;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",s+1);
        l=strlen(s+1)+1;
        s[0]='.';
        initialize();

        memset(v,0,sizeof(v));
        v[1]=0;
        for(i=1;i<l;i++)
        {
            mn=1010;
            for(j=0;j<g[i].size();j++)
            {
                if(mn>v[g[i][j]-1])
                mn=v[g[i][j]-1];
            }
            v[i]=mn+1;
        }
        //for(i=1;i<l;i++)
        //printf("%d ",v[i]);
        //printf("%d\n",v[l-1]);
        for(i=0;i<l;i++)
        g[i].clear();
    }
    return 0;
}
