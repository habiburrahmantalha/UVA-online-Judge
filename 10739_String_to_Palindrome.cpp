#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

string a,b;
int T[1010][1010];
int LCS()
{
    int i,j,l,mn;


    b=a;
    reverse(b.begin(),b.end());

    l=a.size();
    for(i=0;i<=l;i++)
    T[0][i]=T[i][0]=i;

    for(i=0;i<=l;i++)
    {
        for(j=0;j<=l;j++)
        if(a[i]==b[j])
        T[i+1][j+1]=T[i][j];
        else
            T[i+1][j+1]=min(T[i][j],min(T[i+1][j],T[i][j+1]))+1;
    }
    /*
    for(i=0;i<=l;i++)
    {
        for(j=0;j<l;j++)
        printf("%d ",T[i][j]);
        printf("\n");
    }
    */
    return T[l][l];

}
int main()
{
    int tc,t=1,res;
    scanf("%d",&tc);

    while(tc--)
    {
        cin>>a;
        res=LCS();
        printf("Case %d: %d\n",t++,res/2);
    }
    return 0;
}
