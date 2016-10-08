//Problem Type : LIS/LCS
//Time :
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
int a[1010],lis[1010],lds[1010],n;

void LIS()
{
    int i,j,mx;
    memset(lis,0,sizeof(lis));
    lis[n]=1;
    for(i=n-1;i>=1;i--)
    {
        mx=0;
        for(j=i;j<n;j++)
        {
            if(a[i]>=a[j])
                if(mx<lis[j])
                    mx=lis[j];

        }
        lis[i]=mx+1;
    }
}
/*
void LIS()
{
    int i,j,mx,nm;
    a[0]=-1;
    lis[0]=0;
    for(i=1;i<=n;i++)
    {
        mx=0;
        for(j=0;j<i;j++)
        {
            if(a[i]>=a[j])
                if(mx<lis[j])
                    mx=lis[j];

        }

        lis[i]=mx+1;

    }
    /*
    for(i=0;i<=n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    for(i=0;i<=n;i++)
    cout<<lis[i]<<" ";
    cout<<endl;

}
*/
void LDS()
{
    int i,j,mx;
    memset(lds,0,sizeof(lds));
    lds[n]=1;
    for(i=n-1;i>=1;i--)
    {
        mx=0;
        for(j=i;j<=n;j++)
        {
            if(a[i]<a[j])
                if(mx<lds[j])
                    mx=lds[j];
        }
        lds[i]=mx+1;
    }
}
/*
void LDS()
{
    int i,j,mx,nm;
    a[0]=2000000;
    lds[0]=0;
    for(i=1;i<=n;i++)
    {
        mx=0;
        for(j=0;j<i;j++)
        {
            if(a[i]<=a[j])
                if(mx<lds[j])
                    mx=lds[j];

        }

        lds[i]=++mx;

    }

}
*/
int main()
{
    int i,mx;
    int tc;
    scanf("%d",&tc);
    while(tc--)
    //while(scanf("%d",&n) && n)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
        LDS();
        LIS();

        mx=0;
        for(i=1;i<=n;i++)
        //cout<<lis[i]<<" "<<lds[i]<<endl;
        mx=max(lis[i]+lds[i]-1,mx);

        printf("%d\n",mx);
    }
    return 0;
}
