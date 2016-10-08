#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    int i,j,tc,n,price,coin[110],sum;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&price);
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&coin[i]);
            sum+=coin[i];
        }
        int p[sum+5];
        memset(p,0x7F,sizeof(p));
        p[0]=1;
        for(i=0;i<n;i++)
        {
            for(j=sum-coin[i];j>=0;j--)
            {
                if(p[j])
                {
                    if(p[j+coin[i]]>p[j])
                        p[j+coin[i]]=p[j]+1;
                }
            }
        }
        for(i=price;i<=sum;i++)
            if(p[i]!=2139062143)
            {
                printf("%d %d\n",i,p[i]-1);
                break;
            }
    }
    return 0;
}
