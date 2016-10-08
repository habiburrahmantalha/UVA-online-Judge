#include<stdio.h>
#include<math.h>
#include<string>
#include<iostream>
#define LL long long
using namespace std;

LL n(char ch)
{
    return ch-'0';
}
char c(LL x)
{
    return x+'0';
}

string str,res;

void sqr_root()
{
    LL x,y,i,j,ans,z;
    x=n(str[0])*10+n(str[1]);
    //printf("%d\n",x);
    y=floor(sqrt(x));
    //printf("%d\n",y);
    res=c(y);
    ans=y;
    z=y*y;
    for(i=2;i<str.size();i+=2)
    {
        x=x-z;
        x=x*100+n(str[i])*10+n(str[i+1]);
        y=ans*2;
        //printf("%lld\n",y);
        for(j=0;j<=9;j++)
        {
            z=y*10+j;
            //printf("%d ",j);
            if(z*j>x)
            break;
        }
        res+=c(j-1);
        ans=ans*10+(j-1);
        z=(y*10+(j-1))*(j-1);
    }
    //printf("%d\n",ans);
    cout<<res<<endl;
}
int main()
{
    LL tc;
    bool f=false;
    scanf("%lld",&tc);
    while(tc--)
    {
        if(f)
            printf("\n");
        cin>>str;

        if(str.size()&1)
            str.insert(0,1,'0');
        //cout<<str;

        sqr_root();
        f=true;
    }
    return 0;
}
