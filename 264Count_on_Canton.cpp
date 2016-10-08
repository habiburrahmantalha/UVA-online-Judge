#include <stdio.h>
#include <math.h>
int main()
{
	int k, r, n;
	while(scanf("%d",&n)==1)
	{
        k = (int)(sqrt(2 * n) + 0.5);
        r = k * (k + 1)/ 2 - n;
        if(k % 2) printf("TERM %d IS %d/%d\n",n,1+r,k-r);
        else printf("TERM %d IS %d/%d\n",n,k-r,1+r);
	}
	return 0;
}
