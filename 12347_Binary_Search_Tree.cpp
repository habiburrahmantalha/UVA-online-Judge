#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

//int T[1000000 *2 +10],n;
map<int,int>T;
void post_order(int in)
{
    if(T[in]==0)
    return;
    post_order(in*2+1);
    post_order(in*2+2);
    printf("%d\n",T[in]);
}
void insert(int in,int x)
{
    if(T[in]==0)
    {
        T[in]=x;
        return;
    }
    if(T[in]>x)
        insert(in*2+1,x);
    else
        insert(in*2+2,x);
}
int main()
{
    int x;

    while(scanf("%d",&x)==1)
    {
        insert(0,x);

    }
    post_order(0);
    return 0;
}
