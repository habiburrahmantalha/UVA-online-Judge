//Problem Type :
//Time :
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)
map<int,string> m;
int c[55];
void print(int x)
{

    if(c[x]<=9)
        printf("%d",c[x]+1);
    else
        cout<<m[c[x]];
    printf(" of ");
    if(x<=13)
    x=0;
    else if(x<=26)
    x=1;
    else if(x<=39)
    x=2;
    else
    x=3;
    cout<<m[x]<<endl;
}
int main()
{
    m[10]="Jack";
    m[11]="Queen";
    m[12]="King";
    m[13]="Ace";
    m[0]="Clubs";
    m[1]="Diamonds";
    m[2]="Hearts";
    m[3]="Spades";

    int tc,n,i,j,k,S[110][55],D[55],E[55];

    for(k=1,i=0;i<4;i++)
    {
        for(j=1;j<=13;j++)
        c[k++]=j;
    }
    char str[10];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=52;j++)
            scanf("%d",&S[i][j]);
        }

        for(i=1;i<=52;i++)
        D[i]=i;
        gets(str);
        while(gets(str))
        {

            if(strlen(str)==0)
            break;
            sscanf(str,"%d",&k);
            for(j=1;j<=52;j++)
            {
                E[j]=D[S[k][j]];
            }
            for(j=1;j<=52;j++)
            D[j]=E[j];

        }
        for(i=1;i<=52;i++)
        print(D[i]);
        //printf("%d\n",D[i]);

        if(tc)
        printf("\n");
    }
    return 0;
}
