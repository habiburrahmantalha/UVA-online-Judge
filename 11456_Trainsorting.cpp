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
int a[2010],lis[2010],lds[2010],n;

void LIS()
{
    int i,j,mx;
    a[0]=-1;
    lis[0]=0;
    for(i=1;i<=n;i++)
    {
        mx=0;
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j])
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
    */
}
void LDS()
{
    int i,j,mx;
    a[0]=2000000;
    lds[0]=0;
    for(i=1;i<=n;i++)
    {
        mx=0;
        for(j=0;j<i;j++)
        {
            if(a[i]<a[j])
                if(mx<lds[j])
                    mx=lds[j];
        }
        lds[i]=mx+1;

    }

}
int main()
{
    int tc,i,mx;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=n;i>=1;i--)
        scanf("%d",&a[i]);
        LIS();
        LDS();

        mx=0;
        for(i=1;i<=n;i++)
        //cout<<lis[i]<<" "<<lds[i]<<endl;
        mx=max(lis[i]+lds[i]-1,mx);

        printf("%d\n",mx);
    }
    return 0;
}
