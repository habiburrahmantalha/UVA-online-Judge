#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int tc,i,k,n,t=1,x[1000000],m,y;
    scanf("%d",&tc);
    x[0]=0;
    while(tc--)
    {
        scanf("%d",&n);
        y=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x[i]);
            y=max(y,x[i]-x[i-1]);
        }

        for(m=y; ; m++)
        {
            k=m;
            for(i=1;i<=n;i++)
            {
                if(x[i]-x[i-1]>k)
                    k-=x[i]-x[i-1];
                else if(x[i]-x[i-1]==k)
                    k--;

                if(k<0)
                    break;
            }
            if(k>=0)
                break;
        }
        printf("Case %d: %d\n",t++,m);

    }
    return 0;
}
