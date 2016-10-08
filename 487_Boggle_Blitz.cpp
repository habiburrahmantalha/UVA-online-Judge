#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<list>
using namespace std;

list<string> lst;
map<string,int>mp;
char w[500],g[50][50];
int X[]={0,-1,-1,-1,0,1,1,1};
int Y[]={-1,-1,0,1,1,1,0,-1};
int n;
string str,temp;
bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    return true;
}
bool comp(string a,string b)
{

    if(a.size()==b.size())
    return a<b;
    return a.size()<b.size();
}
void backtrack(int x,int y,int i)
{
    int k,j,u,v;
    w[i]=g[x][y];
    if(i>=2)
    {
        str="";
        for(j=0;j<=i;j++)
        str+=w[j];
        if(i>2)
        {

            for(k=4;k<=str.size();k++)
            for(j=0;j<=str.size()-4;j++)
            {

            temp=str.substr(j,k);
            lst.push_back(temp);

            }
        }
        else
            lst.push_back(str);
        //return ;
    }
    for(j=0;j<8;j++)
    {
        u=x+X[j];
        v=y+Y[j];
        if(valid(x,y) && g[x][y]<g[u][v])
            backtrack(u,v,i+1);
    }
}
int main()
{
    int tc,i,j;
    bool NL=false;
    scanf("%d",&tc);
    while(tc--)
    {
        if(NL)
            printf("\n");
        NL=true;

        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",&g[i]);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                backtrack(i,j,0);


        lst.sort();
        lst.unique();

        list<string> :: iterator it;
        for(it=lst.begin();it!=lst.end();it++)
            printf("%s\n",(*it).c_str());
        lst.clear();
    }
    return 0;
}
