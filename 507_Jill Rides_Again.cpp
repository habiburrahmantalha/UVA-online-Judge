#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int tc,i,mx,n,x[100001],y[100001],p[100001],t=1,l,e,s;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        mx=-1000000;
        l=0;
        s=1000001;
        for(i=1;i<n;i++)
        {
            scanf("%d",&x[i]);
            if(x[i]+y[i-1]>=x[i])
            {
                y[i]=x[i]+y[i-1];
                p[i]=p[i-1]+1;
            }
            else
            {
                y[i]=x[i];
                p[i]=1;
            }
            if(mx<y[i])
            {
                mx=y[i];
                l=p[i];
                s=i-p[i]+1;
                e=i+1;
            }
            if(mx==y[i])
            {
                //mx=y[i];
                if(l<p[i])
                {
                    l=p[i];
                    s=i-p[i]+1;
                    e=i+1;
                }
                if(l==p[i])
                {
                    if(s>i-p[i]+1)
                    {
                        s=i-p[i]+1;
                        e=i+1;
                    }
                }
            }
        }
        if(mx<0)
        printf("Route %d has no nice parts\n",t++);
        else
        printf("The nicest part of route %d is between stops %d and %d\n",t++,s,e);
        //printf("%d\n",mx);
    }
    return 0;
}
