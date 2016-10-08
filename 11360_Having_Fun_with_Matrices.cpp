#include<string.h>
#include<vector>
#include<string>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

string g[15];
int n;

void transpose()
{
    int i,j;
    char ch;
    for(i=0;i<n;i++)
    for(j=i;j<n;j++)
    {
        ch=g[i][j];
        g[i][j]=g[j][i];
        g[j][i]=ch;
    }
}
void row(int a,int b)
{
    string temp;
    temp=g[a];
    g[a]=g[b];
    g[b]=temp;
}
void col(int a,int b)
{
    char ch;
    int i;
    for(i=0;i<n;i++)
    {
        ch=g[i][a];
        g[i][a]=g[i][b];
        g[i][b]=ch;
    }
}
void inc()
{
    int i,j;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    g[i][j]=((g[i][j]-'0'+1)%10+'0');
}
void dec()
{
    int i,j;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    g[i][j]=((g[i][j]-'0'+9)%10+'0');
}
int main()
{
    int tc,t=1,i,j,q,a,b;
    string str;

    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>g[i];

        }
        scanf("%d",&q);
        while(q--)
        {
            cin>>str;
            if(str=="transpose")
            transpose();
            else if(str=="row")
            {
                scanf("%d %d",&a,&b);
                row(a-1,b-1);
            }
            else if(str=="col")
            {
                scanf("%d %d",&a,&b);
                col(a-1,b-1);
            }
            else if(str=="inc")
            inc();
            else if(str=="dec")
            dec();
        }
        printf("Case #%d\n",t++);
        for(i=0;i<n;i++)
        cout<<g[i]<<endl;
        printf("\n");
    }
    return 0;
}
