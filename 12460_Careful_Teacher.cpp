//Problem Type : Union Find
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
int p[20010],n;
map<string,int>m;
char a[20010][1000];

void reset()
{
    for(int i=0;i<=n;i++)
    p[i]=i;
}
int find(int x)
{
    if(p[x]==x)
        return x;
    p[x]=find(p[x]);
}
void link(int x,int y)
{
    int xx=find(x);
    int yy=find(y);

    if(xx!=yy)
        p[yy]=p[xx];
}

bool diff_1(int j,int k)
{
    int i,d=0;
    if(strlen(a[j])!=strlen(a[k]))
    return false;
    for(i=0;a[j][i] && a[k][i];i++)
    if(a[j][i]!=a[k][i])
    d++;
    if(d==1)
    return true;
    else
    return false;
}
int main()
{
    char c[1000],b[1000];
    n=1;
    int i=0,j,k;
    while(scanf("%s",a[i]) && a[i][0]!='-' && a[i][1]!='-')
    {
        m[a[i]]=n++;
        i++;
    }

    reset();

    for(j=0;j<i;j++)
    for(k=j+1;k<i;k++)
    {

        if(diff_1(j,k))
        link(m[a[j]],m[a[k]]);
    }

    while(scanf("%s %s",b,&c)==2)
    {
        if(find(m[c])==find(m[b]))
           printf("Yes\n");
        else
            printf("No\n");
    }
    m.clear();
    return 0;
}
