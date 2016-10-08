#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    int tc,n,i,j,w[110],t[45010],sum;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&w[i]);
            sum+=w[i];
        }
        //sort(w,w+n);
        memset(t,0,sizeof(t));
        t[0]=1;

        for(i=0;i<n;i++)
        {
            for(j=sum-w[i];j>=0;j--)
            {
                if(t[j] && j+w[i]<=sum)
                {
                    t[j+w[i]]=t[j]+1;
                }
            }
        }
        int a,b,min=10000000,z;
        if(n&1)
            z=1;
        else
            z=0;
        for(i=0;i<=sum/2;i++)
        {
            if(t[i] && t[sum-i] && (abs(t[i]-t[sum-i])<=z) )
            {
                if(abs(sum-i-i)<min)
                {
                    min=abs(sum-i-i);
                    a=sum-i;
                    b=i;
                }
                //printf("%d %d %d\n",sum,sum-i,i);
                //break;
            }
        }
        printf("%d %d %d %d\n",b,a,n,t[a]+t[b]);
    }
    return 0;
}
