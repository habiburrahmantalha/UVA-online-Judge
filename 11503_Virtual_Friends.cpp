#include<stdio.h>
#include<map>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int P[100010],size[100010];

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
    if(py!=px)
    {
        P[px]=P[py];
        size[py]+=size[px];
    }
}

int main()
{
    int n,i,j,m,tc,a,b,c;
    bool f1,f2;
    map<string,int>mp;
    char s1[30],s2[30];
    scanf("%d",&tc);
    while(tc--)
    {
        n=1;
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%s %s",s1,s2);
            f1=f2=false;
            if(!mp[s1])
            {
                P[n]=n;
                size[n]=1;
                mp[s1]=n++;
                f1=true;
            }
            a=mp[s1];

            if(!mp[s2])
            {
                P[n]=n;
                size[n]=1;
                mp[s2]=n++;
                f2=true;
            }
            b=mp[s2];

            unionset(a,b);

            printf("%d\n",size[findset(a)]);
        }
        mp.clear();
    }
    return 0;
}
