#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

struct E
{
    int i,w,s;
};

vector<E> a;

bool comp(E i,E j)
{
    if(i.w==j.w)
    return i.s<j.s;
    return i.w>j.w;
}

bool comp2(E i,E j)
{
    if(i.s==j.s)
    return i.w<j.w;
    return i.s>j.s;
}
void LIS()
{
    int lis[a.size()];
    int b[a.size()];
    int ind=1,LW,i;
    b[0]=a[0].s;
    lis[0]=1;
    for(i=0;i<a.size();i++)
    {
        LW=lower_bound(b,b+ind,a[i].s)-b;
        lis[i]=LW+1;
	    if(LW==ind)
	    b[ind++]=a[i].s;
	    else
	    b[LW]=a[i].s;
    }
    //for(int i=0;i<a.size();i++)
    //printf("%d %d %d %d\n",a[i].i,a[i].w,a[i].s,lis[i]);

    //printf("%d\n",ind);

	int j=ind;
    vector<E>v;
	for(i=a.size()-1;i>=0;i--)
	if(j==lis[i])
	{
	    while(j==lis[i])
        {
            v.push_back(a[i]);
            i--;
        }
        i++;
	    j--;
	}
	a.clear();
	a=v;
	//for(i=0;i<v.size();i++)
	//printf("%d %d\n",v[i].w,v[i].s);
}

void LIS2()
{
    int lis[a.size()];
    int b[a.size()];
    int ind=1,LW,i;
    b[0]=a[0].s;
    lis[0]=1;
    for(i=0;i<a.size();i++)
    {
        LW=lower_bound(b,b+ind,a[i].w)-b;
        lis[i]=LW+1;
	    if(LW==ind)
	    b[ind++]=a[i].w;
	    else
	    b[LW]=a[i].w;
    }
    //for(int i=0;i<a.size();i++)
    //printf("%d %d %d %d\n",a[i].i,a[i].w,a[i].s,lis[i]);

    printf("%d\n",ind);

	int j=ind;
    vector<E>v;
	for(i=a.size()-1;i>=0;i--)
	if(j==lis[i])
	{
        v.push_back(a[i]);
	    j--;
	}
	for(i=v.size()-1;i>=0;i--)
	printf("%d\n",v[i].i);
}
int main()
{
    //freopen("in.txt","r",stdin);
    E x;
    int ind=1;
    while(scanf("%d %d",&x.w,&x.s)==2)
    {
        x.i=ind++;
        a.push_back(x);

    }
    sort(a.begin(),a.end(),comp);

    //for(int i=0;i<a.size();i++)
    //printf("%d %d %d\n",a[i].i,a[i].w,a[i].s);

    LIS();
    sort(a.begin(),a.end(),comp2);
    LIS2();

    return 0;
}

