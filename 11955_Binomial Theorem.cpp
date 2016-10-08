#include<stdio.h>
#include<string.h>
#define LL long long
#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;

LL p[100][100];
void pascal()
{
    memset(p,0,sizeof(p));
    LL i,j;
    p[0][1]=1;
    for(i=1;i<=55;i++)
    {
        for(j=1;j<=i+1;j++)
        {
            p[i][j]=p[i-1][j]+p[i-1][j-1];
        }
    }
/*
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
            printf("%lld ",p[i][j]);
        printf("\n");
    }
*/
}


int main()
{
    pascal();
    string first,second,third;
    long long t,tc,i,n,j,len;
    char eq[1000];
    scanf("%lld",&tc);
    for(t=1;t<=tc;t++)
    {
        scanf("%s",eq);
        len=strlen(eq);
        j=1;
        first="";
        while(eq[j]!='+')
            first+=eq[j++];
        j++;
        second="";
        while(eq[j]!=')')
            second+=eq[j++];
        j+=2;
        third="";
        while(j<len)
            third+=eq[j++];
        n=atoi(third.c_str());
        //cout<<first<<second<<third<<n;
        printf("Case %lld: ",t);
        if(n==1)
            printf("%s+%s\n",first.c_str(),second.c_str());
        else
        {
            printf("%s^%lld",first.c_str(),n);
            long long a=n-1,b=1;
            if(n>1)
            for(i=2;i<=n;i++)
            {
                if(a==1 && b==1)
                    printf("+%lld*%s*%s",p[n][i],first.c_str(),second.c_str());
                else if(a==1 )
                    printf("+%lld*%s*%s^%lld",p[n][i],first.c_str(),second.c_str(),b++);
                else if(b==1)
                    printf("+%lld*%s^%lld*%s",p[n][i],first.c_str(),a--,second.c_str(),b++);
                else
                    printf("+%lld*%s^%lld*%s^%lld",p[n][i],first.c_str(),a--,second.c_str(),b++);
            }
            printf("+%s^%lld\n",second.c_str(),n);
        }

    }
    return 0;
}
