#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;

int f[30],fin[30],fout[30],source,destination;
int p[30];

void reset()
{
    int i;
    for(i=0;i<26;i++)
    p[i]=i;
}
int find(int x)
{
    if(x!=p[x])
        return x=find(p[x]);
    return p[x];
}
void link(int x,int y)
{
    int xx=find(x);
    int yy=find(y);
    p[xx]=p[yy];
}
bool opened()
{
    int i,in=0,out=0,a,b;
    int odd=0;
    //for(i=0;i<26;i++)
    //if(f[i])
    //cout<<i<<" "<<fin[i]<<" "<<fout[i]<<endl;
    for(i=0;i<26;i++)
    if((fin[i]!=fout[i]))
    {
        a=i;
        odd++;
        break;
    }

    for(i=i+1;i<26;i++)
    if((fin[i]!=fout[i]))
    {
        b=i;
        odd++;
    }


    if(odd!=0 && odd!=2)
    return false;


    if(odd>0)
    if(((fin[a]!=fout[a]+1) && (fout[b]!=fin[b]+1) )&&((fin[b]!=fout[b]+1) && (fout[a]!=fin[b]+1) ))
    return false;

    return true;
}
bool connected()
{

    int y[30],c,i;
    memset(y,0,sizeof(y));
    for(i=0;i<26;i++)
    {
        if(f[i])
        y[find(i)]++;
    }
    c=0;
    for(i=0;i<26;i++)
    if(y[i])
    //cout<<i<<endl;
    c++;
    if(c>1)
    return false;
    return true;


}
int main()
{
    int n,a,b,l,i,tc;
    char s[10000];
    scanf("%d",&tc);
    while(tc--)
    {
        memset(f,0,sizeof(f));
        memset(fin,0,sizeof(fin));
        memset(fout,0,sizeof(fout));
        reset();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {

            scanf("%s",s);
            l=strlen(s);
            a=s[0]-'a';
            fout[a]++;
            b=s[l-1]-'a';
            fin[b]++;
            f[a]=f[b]=1;
            link(a,b);
        }

        if(opened() && connected())
        printf("Ordering is possible.\n");
        else
        printf("The door cannot be opened.\n");
    }
    return 0;
}
