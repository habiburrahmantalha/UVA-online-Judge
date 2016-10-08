#include<stdio.h>
#include<string.h>


int mn,mx,n,h[1000001],w[1000001];

void LIS()
{
    int i,j,k,m,c[n+1];
    mx=0;
    for(i=0;i<n;i++)
    {
        m=0;
        for(j=i-1;j>=0;j--)
        {
            if(h[i]>h[j])
            {
                if(m<c[j])
                {
                    m=c[j];
                    k=j;
                }
            }
        }
        c[i]=m+w[i];
        if(mx<c[i])
        mx=c[i];
    }
}

void LDS()
{
    int i,j,k,m,c[n+1];
    mn=0;
    for(i=0;i<n;i++)
    {
        m=0;
        for(j=i-1;j>=0;j--)
        {
            if(h[i]<h[j])
            {
                if(m<c[j])
                {
                    m=c[j];
                    k=j;
                }
            }
        }
        c[i]=m+w[i];
        if(mn<c[i])
        mn=c[i];
    }
}

int main()
{
    int tc,i,t=1;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",h+i);

        for(i=0;i<n;i++)
        scanf("%d",w+i);

        LIS();

        LDS();
        if(mn>mx)
        printf("Case %d. Decreasing (%d). Increasing (%d).\n",t++,mn,mx);
        else
        printf("Case %d. Increasing (%d). Decreasing (%d).\n",t++,mx,mn);

    }
    return 0;
}
