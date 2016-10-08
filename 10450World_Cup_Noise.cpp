#include<stdio.h>

int main()
{
	long long a[52],i,n,t;
	a[0]=1;
	a[1]=2;
	a[2]=3;
	for(i=3;i<52;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&n);
		printf("Scenario #%d:\n",i+1);
		printf("%lld\n",a[n]);
		printf("\n");
	}
	return 0;
}
