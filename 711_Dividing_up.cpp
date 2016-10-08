#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[10],sum,t[100010];
bool divide()
{
    int i,j,k,l;
    memset(t,0,sizeof(t));
    t[0]=1;
    int mx=0;
    for(i=0;i<6;i++)
    {
        if(a[i])
        {
            for(j=mx;j>=0;j--)
            {
                if(t[j])
                {
                    l=j+i+1;
                    for(k=0;k<a[i];k++)
                    {
                        if(l>sum/2)
                        break;
                        t[l]++;
                        l=l+i+1;
                        if(t[sum/2]>=2)
                        return true;
                    }

                }
            }
            mx=min(mx+a[i]*(i+1),sum/2);
        }
    }
    //for(i=0;i<=sum;i++)
    //printf("%d ",t[i]);
    //printf("%d ",t[sum/2]);
    if(t[sum/2]>=2)
    return true;
    return false;
}
int main()
{
    int tc=1;
    while(scanf("%d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]) && a[0]+a[1]+a[2]+a[3]+a[4]+a[5])
    {
        sum=a[0]*1+a[1]*2+a[2]*3+a[3]*4+a[4]*5+a[5]*6;
        if((sum%2==0) && divide())
        printf("Collection #%d:\nCan be divided.\n\n",tc++);
        else
        printf("Collection #%d:\nCan't be divided.\n\n",tc++);

    }
    return 0;
}
