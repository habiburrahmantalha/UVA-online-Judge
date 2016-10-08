#include<map>
#include<string>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
using namespace std;
#define REP(x,i,j) for(x=i;x<j;x++)

int n,g[101][101],pi[101][101];

void warshal()
{
    int i,j,k;
    REP(k,1,n)REP(i,1,n)REP(j,1,n){
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
        pi[i][j]=k;
    }
}

void print_path(int i,int j)
{
    if(p[i][j]==j)
        printf("%s %s %s %d",)
}
int main()
{
    char s1[25],s2[25],r[25],d[25];
    map<string,int>mp;
    map<pair<int,int>,string> mpr;
    pair<int,int>p;

    n=1;
    while(scanf("%[A-Za-z 0-9]",s1))
    {
        getchar();
        scanf("%[A-Za-z 0-9]",s2);
        getchar();
        scanf("%[A-Za-z 0-9-]",r);
        getchar();
        scanf("%[0-9]",d);
        getchar();

        if(!mp[s1])
            mp[s1]=n++;
        if(!mp[s1])
            mp[s1]=n++;
        p=make_pair(mp[s1],mp[s2]);
        mpr[p]=r;
        g[mp[s1]][mp[s2]]=atoi(d);
    }
    warshal();
    while(scanf("%[A-za-z ]",s1))
    {
        getchar();
        scanf("%[A-za-z ]",s1);
        getchar();


    }

}
