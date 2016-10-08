#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;
int post[10010],pre[10010],N,in;


void pre_to_post(int l,int r)
{
    int j;
    if(l==r)
    {
        post[in++]=pre[l];
        return;
    }
    for( j=l+1;j<=r;j++)
    if(pre[j]>pre[l])
    break;

    pre_to_post(l+1,j-1);
    pre_to_post(j,r);
    post[in++]=pre[l];
    return;
}
int main()
{
    freopen("in.txt","r",stdin);
    N=0;
    while(scanf("%d",&pre[N++])==1)
    {

    }
    in=0;
    pre_to_post(0,N-1);
    return 0;
}
