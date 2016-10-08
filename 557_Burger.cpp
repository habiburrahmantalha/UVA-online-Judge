#include<stdio.h>

double p[50010];

void burger()
{
    int i;
    p[0]=1;
    p[1]=.5;
    for(i=2;i<=50000;i++)
        p[i]=p[i-1]*double(2*i-1)/double(2*i);

}

int main()
{
    burger();
    int tc,n;
    double res;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);
        res=1-p[n/2-1];
        printf("%.4lf\n",res);
    }
    return 0;
}
