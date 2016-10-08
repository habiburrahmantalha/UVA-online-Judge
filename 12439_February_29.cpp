#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

bool leap_year(long long x)
{
    if((x%4==0 && x%100!=0) || x%400==0)
    return true;

    return false;
}
int main()
{
    string m1,m2;
    long long d1,d2,y1,y2,l1,l2,tc,t=1;
    scanf("%lld",&tc);
    while(tc--)
    {
        cin>>m1;
        scanf("%lld, %lld",&d1,&y1);
        cin>>m2;
        scanf("%lld, %lld",&d2,&y2);



        if(m1!="January" && m1!="February")
        y1++;

        while(!leap_year(y1) && y1<=y2)
        y1++;

        if(m2=="January" || (m2=="February" && d2!=29) )
        y2--;

        while(!leap_year(y2) && y2>=y1)
        y2--;

        //cout<<y1<<" "<<y2<<endl;

        l1=y1/4+y1/400-y1/100;
        l2=y2/4+y2/400-y2/100;

        if(y1>y2 || y2<y1)
        printf("Case %lld: 0\n",t++);
        else
        printf("Case %lld: %lld\n",t++,l2-l1+1);
    }
    return 0;
}
