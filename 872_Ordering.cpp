#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<ctype.h>
using namespace std;

char v[30],res[30];
int g[30][30],n,visit[30];
bool result;
bool check(int k,int x)
{
    for(int i=0;i<k;i++)
    if(g[x][res[i]-'A'])
    return false;
    return true;
}

void backtrack(int k)
{
    int i;
    if(k==n)
    {
        result=true;
        for(i=0;i<n-1;i++)
        printf("%c ",res[i]);
        printf("%c\n",res[i]);
        return;
    }
    for(i=0;i<n;i++)
    {
       if(visit[i]==0 && check(k,v[i]-'A'))
       {
           res[k]=v[i];
           visit[i]=1;
           backtrack(k+1);
           visit[i]=0;
       }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    bool f=false;
    int tc,i,t;
    char a,b,input[500];
    scanf("%d",&tc);
    gets(input);
    gets(input);
    for(t=0;t<tc;t++)
    {
        result=false;
        if(f)
        printf("\n");
        f=true;
        n=0;
        memset(g,0,sizeof(g));
        memset(visit,0,sizeof(visit));
        gets(input);
        for(i=0;input[i]!=0;i++)
        if(isalpha(input[i]))
        v[n++]=input[i];
        sort(v,v+n);

        gets(input);

        for(i=0;input[i]!=0;i++)
        if(isalpha(input[i]))
        {
            a=input[i];
            i++;
            while(!isalpha(input[i]))i++;
            b=input[i];
            //printf("%c %c\n",a,b);
            g[a-'A'][b-'A']=1;

        }
        backtrack(0);
        if(!result)
        printf("NO\n");
        if(t<tc-1)
        gets(input);
    }
    return 0;
}
