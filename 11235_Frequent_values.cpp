#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

int ar[100010];
int st[100010*2+10];
int f[100010];

void build_fr(int n)
{
    int i,j,k,c;
    for(i=0;i<n;i++)
    {
        j=i;
        c=0;
        while(ar[i]==ar[j])
        {
            j++;
            c++;
        }
        for(k=i;k<j;k++)
        f[k]=c;
        i=j-1;
    }
}
int build_st(int in,int L,int R)
{
    if(L==R)
       return st[in]=L;
    else
    {
        int M=(L+R)/2;
        int a=build_st(2*in+1,L,M);
        int b=build_st(2*in+2,M+1,R);

        if(f[a]<=f[b])
            return st[in]=a;
        else
            return st[in]=b;
    }
}

int rmq(int in,int L,int R,int i,int j)
{
    if(i>R || j< L)
        return -1;
    if(L>=i && R<=j && ar[L]==ar[R])
        return st[in];
    int M=(L+R)/2;
    int a=rmq(2*in+1,L,M,i,j);
    int b=rmq(2*in+2,M+1,R,i,j);

    if(a==-1)
    return b;
    if(b==-1)
    return a;

    if(f[a]<=f[b])
        return a;
    else
        return b;
}
void print(int x,int y[])
{
    for(int i=0;i<x;i++)
    printf("%d ",y[i]);
    printf("\n");
}
int main()
{
    int n,q,i,a,b;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&q);
        for(i=0;i<n;i++)
        scanf("%d",&ar[i]);

        build_fr(n);
        build_st(0,0,n);

        print(n,f);
        while(q--)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",f[rmq(0,0,n,a-1,b-1)]);
        }
    }


    //print(n*2+1,st);

}

