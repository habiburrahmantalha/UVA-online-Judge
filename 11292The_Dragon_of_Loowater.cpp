#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{

    int m,n,i,j,sum,count,in,dragon[20000+5],knight[20000+5];

    while(scanf("%d %d",&n,&m) && n && m)
    {
        if(n>m)
        {
            for(i=0;i<n;i++)
            scanf("%d",&dragon[i]);

            for(i=0;i<m;i++)
            scanf("%d",&knight[i]);
            printf("Loowater is doomed!\n");
        }
        else
        {
            for(i=0;i<n;i++)
            scanf("%d",&dragon[i]);

            for(i=0;i<m;i++)
            scanf("%d",&knight[i]);

            sort(dragon,dragon+n);
            sort(knight,knight+m);
            in=count=sum=0;
            for(i=0;i<n;i++)
            {
                for(j=in;j<m;j++)
                {
                    if(dragon[i]<=knight[j])
                    {
                        sum+=knight[j];
                        in=j+1;
                        count++;
                        break;
                    }
                }
            }
            if(count==n)
            printf("%d\n",sum);
            else
            printf("Loowater is doomed!\n");
        }

    }
    return 0;
}
