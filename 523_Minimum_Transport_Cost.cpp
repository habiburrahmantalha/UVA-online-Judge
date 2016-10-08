#include<stdio.h>
#include<string.h>
#include<vector>
#include<stdlib.h>
#include<sstream>
#include<iostream>
#include<string>
using namespace std;
vector<int>v1,v2;
int g[111][111],pi[111][111];
int tax[111];
int n;

void path1(int a,int b)
{
    if(a==b)
    {
        v1.push_back(a);
        return;
    }
    else
    {
        path1(a,pi[a][b]);
        v1.push_back(b);
    }
}
void path2(int a,int b)
{
    if(a==b)
    {
        v2.push_back(a);
        return;
    }
    else
    {
        path2(a,pi[a][b]);
        v2.push_back(b);
    }
}

void warshal()
{
    int k,i,j;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                /*
                if(g[i][j]==g[i][k]+tax[k]+g[k][j])
                {

                    if(pi[i][j]!=pi[k][j] && pi[i][j]!=0)
                    {
                        v1.clear();
                        v2.clear();
                        int b=pi[i][j];
                        path1(i,j);
                        pi[i][j]=pi[k][j];
                        path2(i,j);
                        int l=v1.size();
                        if(l>v2.size())
                        l=v2.size();

                        for(int a=0;a<l;a++)
                        {
                                if(v1[a]!=v2[a])
                                {
                                    if(v1[a]<v2[a])
                                    pi[i][j]=b;
                                    break;
                                }
                        }

                    }
                }
                */
                if(g[i][j]>g[i][k]+tax[k]+g[k][j])
                {
                    g[i][j]=g[i][k]+tax[k]+g[k][j];
                    pi[i][j]=pi[k][j];
                }
            }
        }
    }
}
void reset()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(g[i][j]==-1)
                g[i][j]=10000000;
            if(i!=j && g[i][j]!=-1)
            pi[i][j]=i;
            else
            pi[i][j]=0;
        }
}
void print_path(int a,int b)
{
    if(a==b)
    {
        printf("%d",a);
        return;
    }
    else
    {
        print_path(a,pi[a][b]);
        printf("-->%d",b);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,a,b,tc;
    char ch,z[10];
    string str;
    bool f=false;
    scanf("%d",&tc);
    while(tc--)
    {

        for(i=1;;i++)
        {
            scanf("%d",&g[1][i]);
            ch=getchar();
            if(ch==10)
            break;
        }
        n=i;
        for(i=2;i<=n;i++)
        for(j=1;j<=n;j++)
        scanf("%d",&g[i][j]);


        for(i=1;i<=n;i++)
        scanf("%d",&tax[i]);
        reset();
        warshal();
        getchar();

        while(getline(cin,str))
        {
            if(str.size()==0)
            break;
            if(f)
            printf("\n");
            f=true;


            stringstream ss(str);
            ss>>a>>b;

            printf("From %d to %d :\n",a,b);
            printf("Path: ");
            print_path(a,b);
            printf("\n");
            printf("Total cost : %d\n",g[a][b]);
            //printf("\n");
        }
        //printf("\n");
    }
    return 0;
}
