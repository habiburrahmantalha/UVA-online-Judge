#include<stdio.h>
#include<string.h>
#define LL long long

LL a[21],n;
LL max_product()
{
    LL i,j;
    LL m[21][21],max=0;
    memset(m,0,sizeof(m));
    for(i=0;i<n;i++)
    {
        m[i][0]=a[i];
        j=1;
        while(j<=i)
        {
            m[i][j]=a[i]*m[i-1][j-1];
            j++;
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(max<m[i][j])
                max=m[i][j];

    return max;
}

int main()
{
    LL i,res,t=1;
    while(scanf("%lld",&n)==1)
    {
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        res=max_product();
        printf("Case #%lld: The maximum product is %lld.\n\n",t++,res);
    }
    return 0;
}
