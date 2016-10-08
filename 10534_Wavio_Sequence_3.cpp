//.108
#include <vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

int s[10001],n,mx,lis[10001],lds[10001];


int LISr()
{

	int b[n];
	int ind=1,LW,i;
	lds[n-1]=1;
	b[0]=s[n-1];

	for(i=n-2;i>=0;i--)
	{
	    LW=lower_bound(b,b+ind,s[i])-b;
	    lds[i]=LW+1;
	    if(LW==ind)
	    b[ind++]=s[i];
	    else
	    b[LW]=s[i];
	}

}

int LIS()
{
	int b[n];
	int ind=1,LW,i;
	lis[0]=1;
	b[0]=s[0];

	for(i=1;i<n;i++)
	{
	    LW=lower_bound(b,b+ind,s[i])-b;
	    lis[i]=LW+1;
	    if(LW==ind)
	    b[ind++]=s[i];
	    else
	    b[LW]=s[i];
	}
}


int main()
{
    int tc,i;

    while(scanf("%d",&n)==1)
    {

        for(i=0;i<n;i++)
        scanf("%d",s+i);

        LIS();

        //reverse(s,s+n);
        LISr();

        //reverse(lds.begin(),lds.end());
        /*
        for(i=0;i<n;i++)
        printf("%d ",lis[i]);
        printf("\n");

        for(i=0;i<n;i++)
        printf("%d ",lds[i]);
        printf("\n");
        //*/
        mx=0;
        for(i=0;i<n;i++)
        mx=max(mx,min(lis[i],lds[i]));

        printf("%d\n",mx*2-1);
    }
    return 0;
}
