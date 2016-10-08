#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int tc,n,m,i,f[1100],x,c,j;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d %d",&n,&m);
        n=pow(2,n);
        for(i=1;i<=n;i++)
            f[i]=1;
        for(i=0;i<m;i++)
        {
            scanf("%d",&x);
            f[x]=0;
        }
        c=0;
        while(n>1)
        {
            j=1;
            for(i=1;i<=n;i+=2)
            {

                if(f[i] && f[i+1])
                {
                    f[j++]=1;
                }
                else if(!f[i] && !f[i+1])
                {
                    f[j++]=0;
                }
                else
                {
                    c++;
                    f[j++]=1;
                }

            }
            n/=2;
        }
        printf("%d\n",c);
    }
    return 0;
}
