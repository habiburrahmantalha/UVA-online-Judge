//.012
#include <vector>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int s[1000001],n;

void LIS()
{
	vector<int>lis(n);
	int b[n];
	int ind=1,LW,i,mx=0;
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

	    //mx=max(mx,lis[i]);
	}
	printf("Max hits: %d\n",ind);

    int j=ind;
    vector<int>v;
	for(i=n-1;i>=0;i--)
	if(j==lis[i])
	{
	    v.push_back(s[i]);
	    j--;
	}
	for(i=v.size()-1;i>=0;i--)
	printf("%d\n",v[i]);


	//return lis;
}
int main()
{
    int tc,a;
    char x[10];
    bool f=false;
    scanf("%d",&tc);
    gets(x);
    gets(x);
    while(tc--)
    {
        if(f)
        printf("\n");
        f=true;
        n=0;
        while(gets(x))

        {
            if(strlen(x)==0)
            break;
            sscanf(x,"%d",&a);
            s[n++]=a;
        }
        LIS();

        //for(int i=1;i<v.size();i++)
        //printf("%d ",t[i]);

    }
    return 0;
}
