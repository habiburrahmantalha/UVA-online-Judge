#include <vector>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,p,q,x[65000],y[65000],t=1,fp[65000],fq[65000];
vector<int>princess,princeT,prince;

void LCS()
{
    int i,j;
    int T[prince.size()][princess.size()];
    memset(T,0,sizeof(T));


    for(i=1;i<=prince.size();i++)
    {
        for(j=1;j<=princess.size();j++)
        if(prince[i-1]==princess[j-1])
        T[i][j]=T[i-1][j-1]+1;
        else
        T[i][j]=max(T[i-1][j],T[i][j-1]);
    }
    printf("Case %d: %d\n",t++,T[prince.size()][princess.size()]);
}

void LIS()
{
    int lis[p+5];
    int b[p+5];
    int ind=1,LW,i;
    b[0]=x[0];
    lis[0]=1;
    for(i=0;i<=p;i++)
    {
        LW=lower_bound(b,b+ind,x[i])-b;
        lis[i]=LW+1;
	    if(LW==ind)
	    b[ind++]=x[i];
	    else
	    b[LW]=x[i];
    }
    int j=ind;
    prince.clear();
    memset(fp,0,sizeof(fp));
    for(i=p;i>=0;i--)
    {
        if(j==lis[i])
        {
            while(j==lis[i])
            {
                prince.push_back(x[i]);
                fp[x[i]]=1;
                i--;
            }
            i++;
            j--;
        }
    }
    /*
	int j=1;
    princeT.clear();
    memset(fp,0,sizeof(fp));
	for(i=0;i<=p;i++)
	if(j==lis[i])
	{
	    while(j==lis[i])
        {
            princeT.push_back(x[i]);
            fp[x[i]]=1;
            i++;

        }
        i--;
	    j++;
	}
    */
    ///*
	for(i=0;i<prince.size();i++)
	printf("%d ",prince[i]);
	printf("\n");
    //*/
}

void LIS2()
{
    int lis[q+5];
    int b[q+5];
    int ind=1,LW,i;
    b[0]=y[0];
    lis[0]=1;
    for(i=0;i<=q;i++)
    {
        LW=lower_bound(b,b+ind,y[i])-b;
        lis[i]=LW+1;
	    if(LW==ind)
	    b[ind++]=y[i];
	    else
	    b[LW]=y[i];
    }
    int j=ind;
    princess.clear();
	for(i=q;i>=0;i--)
	if(j==lis[i])
	{
	    k=i;
	    while(j==lis[k])
        {
            if(fp[y[i]]==1)
            {
                princess.push_back(y[i]);
                //i++;
                //break;
            }
            i--;
        }
        i++;
	    j--;
	}

    /*
	int j=1;
    princess.clear();
    //memset(fq,0,sizeof(fq));
	for(i=0;i<=q;i++)
	if(j==lis[i])
	{
	    while(j==lis[i] && fp[y[i]]==1)
        {
            princess.push_back(y[i]);
            fq[y[i]]=1;
            i++;
        }
        i--;
	    j++;
	}
    prince.clear();
    for(i=0;i<princeT.size();i++)
    if(fq[princeT[i]])
    prince.push_back(princeT[i]);
    //*/
    ///*
	for(i=0;i<princess.size();i++)
	printf("%d ",princess[i]);
	printf("\n");
	//*/
}

int main()
{
    freopen("in.txt","r",stdin);
    int i,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&n,&p,&q);

        for(i=0;i<=p;i++)
            scanf("%d",&x[i]);

        for(i=0;i<=q;i++)
            scanf("%d",&y[i]);

        LIS();
        LIS2();
        LCS();

    }


    return 0;
}
