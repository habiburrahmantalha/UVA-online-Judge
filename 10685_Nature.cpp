#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
using namespace std;

int n,P[5010],s[5010];
void reset()
{
    int i;
    for(i=0;i<n;i++)
    {
        P[i]=i;
        s[i]=1;
    }
}
int findset(int x)
{
    if(x!=P[x])
        P[x]=findset(P[x]);
    return P[x];
}

void unionset(int x,int y)
{
    int px=findset(x);
    int py=findset(y);
    if(px!=py)
    {
        P[px]=P[py];
        s[py]+=s[px];
    }

}
int main()
{
    int m,i,j,mx,c;
    map<string,int>mp;
    char a[32],b[32],str[32];

    while(scanf("%d %d",&n,&m))
    {
        reset();

        if(n==0 & m==0)
            break;

        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            mp[str]=i;
        }
        for(i=0;i<m;i++)
        {
            scanf("%s %s",a,b);
            unionset(mp[a],mp[b]);
        }
        mx=0;

        for(i=0;i<n;i++)
        {
            //c=findset(i);
            if(mx<s[i])
            mx=s[i];
        }
        printf("%d\n",mx);
        mp.clear();
    }
    return 0;
}
