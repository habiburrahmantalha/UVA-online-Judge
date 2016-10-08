#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct st
{
    int p,n;
};
bool cmp (st a,st b)
{
    if(a.p==b.p)
    return a.n>b.n;
    return a.p>b.p;
}

st x[10010];
int y[10010];
int i,j,sum,p1,p2,n,c,n1,n2,s;
bool fn1,fn2,fp1,fp2,z;

bool zero()
{
    z=false;
    for(i=0;i<c;i++)
    if(x[i].n==0)
    return true;
}
bool even()
{
    s=0;
    for(i=0;i<c;i++)
    if(x[i].n<0)
    s++;
    if(s&1)
    return false;
    return true;

}
void check()
{
    fn1=fn2=fp1=fp2=false;
    for(i=c-1;i>=0;i--)
    if(x[i].n>0)
    {
        p1=x[i].n;
        fp1=true;
        break;
    }
    for(i=c-1;i>=0;i--)
    if(x[i].n<0)
    {
        n1=x[i].n;
        fn1=true;
        break;
    }
    for(i=c;i<n;i++)
    if(x[i].n>=0)
    {
        p2=x[i].n;
        fp2=true;
        break;
    }
    for(i=c;i<n;i++)
    if(x[i].n<0)
    {
        n2=x[i].n;
        fn2=true;
        break;
    }
}
int main()
{

    while(scanf("%d %d",&n,&c) && n+c)
    {

        for(i=0;i<n;i++)
        {
            scanf("%d",&y[i]);
            x[i].n=y[i];
            x[i].p=abs(y[i]);
        }
        sort(x,x+n,cmp);
        sort(y,y+n);

        if(zero())
        {
            sum=0;
            for(i=n-1,j=0;i>=0 && j<c;i--,j++)
            sum+=y[i];
            printf("%d\n",sum);

        }
        else if(even())
        {
            sum=0;
            for(i=0;i<c;i++)
            sum+=x[i].n;
            printf("%d\n",sum);
        }
        else
        {
            check();

            sum=0;
            for(i=0;i<c;i++)
            sum+=x[i].n;

            if(fp1 && fp2 && fn1 && fn2)
            {
                if(n1*n2>p1*p2)
                {
                    sum-=p1;
                    sum+=n2;
                }
                else
                {
                    sum-=n1;
                    sum+=p2;
                }
            }
            else if(fn1 && !fn2 && !fp1 && !fp2 )
            {

            }
            else if(fn1 && fn2 && !fp1 && !fp2 )
            {
                sum=0;
                for(i=n-1,j=0;i>=0 && j<c;i--,j++)
                sum+=y[i];
            }
            else if(fn1 && fn2 && fp1 && !fp2 )
            {
                sum-=p1;
                sum+=n2;
            }
            else if(fn1 && fn2 && !fp1 && fp2 )
            {
                if(p2==0)
                {
                    sum=0;
                    for(i=n-1,j=0;i>=0 && j<c;i--,j++)
                    sum+=y[i];

                }
                else
                {
                    sum-=n1;
                    sum+=p2;
                }
            }
            else if(fn1 && !fn2 && fp1 && !fp2 )
            {

            }
            else if(fn1 && !fn2 && fp1 && fp2 )
            {
                if(p2==0)
                {
                    sum=0;
                    for(i=n-1,j=0;i>=0 && j<c;i--,j++)
                    sum+=y[i];

                }
                else
                {
                    sum-=n1;
                    sum+=p2;
                }
            }
            else if(fn1 && !fn2 && !fp1 && fp2 )
            {
                if(p2==0)
                {
                    sum=0;
                    for(i=n-1,j=0;i>=0 && j<c;i--,j++)
                    sum+=y[i];

                }
                else
                {
                    sum-=n1;
                    sum+=p2;
                }
            }

            printf("%d\n",sum);
        }
    }
    return 0;
}
