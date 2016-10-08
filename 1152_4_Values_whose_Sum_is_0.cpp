#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int tc,i,j,k,l,m,res,n,x,A[4010],B[4010],C[4010],D[4010],E[4010*4010],F[4010*4010];
struct X
{
    int n,f;
};
X G[4010*4010];

int find(int y)
{
    int low=0;
    int high=m;
    int mid;
    while(low<=high)
    {
        mid=(high+low)/2;

        if(G[mid].n==y)
        return mid;

        if(y<G[mid].n)
        high=mid-1;
        else
        low=mid+1;
    }
    return -1;
}

int main()
{

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);

        k=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            E[k++]=A[i]+B[j];

        l=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            F[l++]=C[i]+D[j];

        sort(F,F+l);
        m=0;
        G[m].n=F[0];
        G[m].f=1;
        for(i=1;i<l;i++)
        {
            if(G[m].n==F[i])
            G[m].f++;
            else
            {
                G[++m].n=F[i];
                G[m].f=1;
            }
        }

        res=0;
        for(i=0;i<k;i++)
        {
            x=E[i];
            j=find(-x);
            //cout<<j;
            if(j>=0)
            res+=G[j].f;

        }


        printf("%d\n",res);

        if(tc)
        printf("\n");

    }
    return 0;
}
