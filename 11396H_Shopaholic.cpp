#include<stdio.h>
#include<algorithm>

using namespace std;


int main()
{
    int tc,p[20000+5],n,i,sum;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        scanf("%d",&p[i]);

        sort(p,p+n);

        sum=0;
        for(i=n-3;i>=0;i-=3)
        //
        {
            //printf("%d\n",p[i]);
            sum+=p[i];

        }
        printf("%d\n",sum);

    }
    return 0;
}
