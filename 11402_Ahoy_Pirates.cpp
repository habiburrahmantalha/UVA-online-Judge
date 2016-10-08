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

#define N 1024005
#define S 1
#define C 2
#define F 3

int n;
int A[N+5];
int T[N*5];
int U[N*5];

void build_tree(int in,int L,int R)
{
    U[in]=0;
    if(L==R)
    {
        T[in]=A[L];
        return ;
    }
    int M=(L+R)/2;
    int a=2*in;
    int b=2*in+1;

    build_tree(a,L,M);
    build_tree(b,M+1,R);

    T[in]=T[a]+T[b];

}
int apply_flip(int x)
{
    if(x==S)
        return C;
    if(x==C)
        return S;
    if(x==F)
        return 0;
    return F;
}
void lazy_propagate(int in,int L,int R)
{
    if(U[in]==0)
        return ;

    if(U[in]==S)
        T[in]=R-L+1;
    else if(U[in]==C)
        T[in]=0;
    else if(U[in]==F)
        T[in]=(R-L+1)-T[in];

    if(L!=R)
    {
        int a=2*in;
        int b=2*in+1;
        if(U[in]==S || U[in]==C)
            U[a]=U[b]=U[in];
        else
        {
            U[a]=apply_flip(U[a]);
            U[b]=apply_flip(U[b]);
        }
    }
    U[in]=0;
}
void set_tree(int i,int j,int in,int L,int R)
{
    lazy_propagate(in,L,R);
    if(j<L || i>R)
        return ;
    if(L==R)
    {
        T[in]=1;
        U[in]=0;
        return;
    }
    int M=(L+R)/2;
    int a=2*in;
    int b=2*in+1;
    if(L>=i && R<=j)
    {
        T[in]=R-L+1;
        U[a]=U[b]=S;
        return;
    }
    set_tree(i,j,a,L,M);
    set_tree(i,j,b,M+1,R);

    T[in]=T[a]+T[b];
}

void clear_tree(int i,int j,int in,int L,int R)
{
    lazy_propagate(in,L,R);
    if(j<L || i>R)
        return ;
    if(L==R)
    {
        T[in]=0;
        U[in]=0;
        return;
    }
    int M=(L+R)/2;
    int a=2*in;
    int b=2*in+1;
    if(L>=i && R<=j)
    {
        T[in]=0;
        U[a]=U[b]=C;
        return;
    }
    clear_tree(i,j,a,L,M);
    clear_tree(i,j,b,M+1,R);

    T[in]=T[a]+T[b];
}

void flip_tree(int i,int j,int in,int L,int R)
{
    lazy_propagate(in,L,R);
    if(j<L || i>R)
        return ;
    if(L==R)
    {
        T[in]=T[in]==1?0:1;
        return;
    }
    int M=(L+R)/2;
    int a=2*in;
    int b=2*in+1;
    if(L>=i && R<=j)
    {
        T[in]=(R-L+1)-T[in];
        U[a]=apply_flip(U[a]);
        U[b]=apply_flip(U[b]);

        return;
    }
    flip_tree(i,j,a,L,M);
    flip_tree(i,j,b,M+1,R);

    T[in]=T[a]+T[b];
}
int query(int i,int j,int in,int L,int R)
{
    if(j<L || i>R)
        return -1;
    lazy_propagate(in,L,R);

    if(L>=i && R<=j)
        return T[in];

    int M=(L+R)/2;
    int a=2*in;
    int b=2*in+1;

    int x=query(i,j,a,L,M);
    int y=query(i,j,b,M+1,R);

    if(x<0)
        return y;
    if(y<0)
        return x;
    return x+y;



}
int main()
{
    int tc,t=1,q,Q,m,p,i,j,a,b;
    char str[110];
    scanf("%d",&tc);
    while(tc--)
    {

        scanf("%d",&m);
        n=0;
        while(m--)
        {
            scanf("%d %s",&p,str);

            for(i=0;i<p;i++)
            {
                for(j=0;str[j];j++)
                {
                    A[n++]=str[j]-'0';
                }
            }
        }
        /*
        for(i=0;i<n;i++)
            cout<<A[i];
        cout<<endl;
        */
        build_tree(1,0,n-1);

        scanf("%d",&q);
        Q=1;
        printf("Case %d:\n",t++);
        while(q--)
        {
            scanf("%s %d %d",str,&a,&b);
            if(str[0]=='F')
            {
                set_tree(a,b,1,0,n-1);
            }
            else if(str[0]=='I')
            {
                flip_tree(a,b,1,0,n-1);
            }
            else if(str[0]=='E')
            {
                clear_tree(a,b,1,0,n-1);
            }
            else
            {
                int res = query(a,b,1,0,n-1);
                if(res<0)
                    res=0;
                printf("Q%d: %d\n",Q++,res);
            }
        }
    }
    return 0;
}
