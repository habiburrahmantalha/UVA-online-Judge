//TLE

#include<stdio.h>
#include<string.h>


int n,s[10001],a[10001],b[10001],mx;

void LIS()
{
    int i,j,m;
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++)
    {
        m=0;
        for(j=i-1;j>=0;j--)
            if(s[i]>s[j])
                if(m<a[j])
                    m=a[j];
        a[i]=m+1;
    }
    //for(i=0;i<n;i++)
    //printf("%d ",a[i]);
    //printf("\n");
}

void LISr()
{
    int i,j,m;
    memset(b,0,sizeof(b));
    mx=0;
    for(i=n-1;i>=0;i--)
    {
        m=0;
        for(j=i+1;j<n;j++)
            if(s[i]>s[j])
                if(m<b[j])
                    m=b[j];


        b[i]=m+1;
        if(b[i]==a[i])
        if(mx<b[i])
        mx=b[i];
    }
    //for(i=0;i<n;i++)
    //printf("%d ",b[i]);
    //printf("\n");
}

int main()
{
    int tc,i;


    while(scanf("%d",&n)==1)
    {

        for(i=0;i<n;i++)
        scanf("%d",s+i);


        LIS();

        LISr();

        printf("%d\n",(mx*2)-1);
    }
    return 0;
}
