//.096
#include <vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

int s[10001],n,mx;

vector<int> LIS()
{
	vector<int>lis(n);
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
	for(i=0;i<ind;i++)
	printf("%d ",b[i]);
	printf("\n");
	return lis;
}

int main()
{
    int tc,i;

    while(scanf("%d",&n)==1)
    {

        for(i=0;i<n;i++)
        scanf("%d",s+i);

        vector<int> lis = LIS();

        reverse(s,s+n);
        vector<int> lds = LIS();
        reverse(lds.begin(),lds.end());
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
        //if(lis[i]==lds[i])
        mx=max(mx,min(lis[i],lds[i]));

        printf("%d\n",mx*2-1);
    }
    return 0;
}
