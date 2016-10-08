#include<stdio.h>

int t,n,a[30],x[30],mx,y[30],yk;

void backtrack(int sum,int j,int k)
{
    int i;
    x[k]=a[j];
    k++;
    if(mx<sum && sum<t)
    {
        mx=sum;
        yk=k;
        for(i=0;i<k;i++)
            y[i]=x[i];
    }
    if(sum>t)
    {
        if(mx<sum-a[j])
        {
            k--;
            mx=sum-a[j];
            yk=k;
            for(i=0;i<k;i++)
            y[i]=x[i];


        }
        return;
    }
    if(mx<sum && sum==t)
    {
        mx=sum;
        yk=k;
        for(i=0;i<k;i++)
            y[i]=x[i];
        return;
    }
    for(i=j+1;i<n;i++)
    {
        backtrack(sum+a[i],i,k);
    }

}
int main()
{
    int i;
    while(scanf("%d",&t)==1)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        mx=0;
        for(i=0;i<n;i++)
        backtrack(a[i],i,0);

        for(i=0;i<yk;i++)
            printf("%d ",y[i]);
        printf("sum:%d\n",mx);
    }

    return 0;
}
