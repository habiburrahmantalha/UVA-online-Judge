#include<stdio.h>
#include<string.h>

int main()
{
    int n,m,j,i,mn,x[100010],s[100010],sum;
    while(scanf("%d %d",&n,&m)==2)
    {
        memset(s,0,sizeof(s));
        j=0;
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            sum+=x[i];
            while(sum>=m)
            {
                s[j]=i-j+1;
                sum-=x[j];
                j++;
            }
        }
        mn=2000000;
        for(i=0;i<n;i++)
        //printf("%d ",s[i]);
        if(mn>s[i] && s[i]>0)
        mn=s[i];

        if(mn==2000000)
        mn=0;
        printf("%d\n",mn);
    }
    return 0;
}
