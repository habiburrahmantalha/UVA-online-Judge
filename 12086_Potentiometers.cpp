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

#define LSOne(x) (x&-x)
int ft[200010],n;
void ft_adjust(int i,int x)
{
    for(;i<=n;i+=LSOne(i))
    {
        ft[i]+=x;
        if(i==0)
        break;
    }
}
int ft_rsq1(int i)
{
    int sum=0;
    for(;i>=0;i-=LSOne(i))
    {
        sum+=ft[i];
        if(i==0)
        break;
    }
    return sum;
}
int ft_rsq2(int i,int j)
{
    if(i==0)return ft_rsq1(j);
    return ft_rsq1(j)-ft_rsq1(i-1);
}
int main()
{
    int t=1,i,j,x,y;
    bool f=false;
    string str;
    while(scanf("%d",&n) && n)
    {
        if(f)
        printf("\n");
        f=true;
        memset(ft,0,sizeof(ft));
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            ft_adjust(i,x);
        }
        printf("Case %d:\n",t++);
        while(true)
        {
            cin>>str;
            if(str=="END")
            break;
            else if(str=="S")
            {
                scanf("%d %d",&i,&x);
                y=ft_rsq2(i-1,i-1);
                ft_adjust(i-1,-y);
                ft_adjust(i-1,x);
            }
            else if(str=="M")
            {
                scanf("%d %d",&i,&j);
                printf("%d\n",ft_rsq2(i-1,j-1));
            }
        }
    }
    return 0;
}
