#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define LL long long

LL N,len;
char str[30];

LL fact(LL n)
{
    LL f=1,i;
    for(i=1;i<=n;i++)
    f*=i;
    return f;
}

void N_permutation(LL n,LL m)
{
    LL x;
    LL p,q,i;
    //printf("------\n");
    if(n==0)
    return;

    //cout<<str<<endl;
    sort(str+m,str+len);
    //cout<<str<<endl;

    x=fact(n);
    p=x/n;

    for(i=1;i<=len;i++)
    if(p*i>=N)
    {
        //printf("%d %d\n",i,p);
        q=i;
        break;
    }
    N-=p*(q-1);

    //printf("%d %d %d\n",x,p,q);

    char t=str[m];
    str[m]=str[m+q-1];
    str[m+q-1]=t;

    //cout<<str<<endl;
    N_permutation(n-1,m+1);
}
int main()
{
    LL tc;

    scanf("%lld",&tc);

    while(tc--)
    {
        cin>>str>>N;
        N+=1;
        len=strlen(str);
        N_permutation(len,0);
        cout<<str<<endl;
    }
    return 0;
}
