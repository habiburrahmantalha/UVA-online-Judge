//Problem Type :    base convertion
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
#define LL long long

string num;

char digit_char[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
LL digit_int[130];

LL POW(LL n,LL p) {LL x=1; for(LL i=0;i<p;i++) x*=n; return x;}

LL to_decimal(string str,LL b)
{
    LL i,j;
    LL in_dec=0;
    for(i=0,j=str.size()-1;i<str.size();i++,j--)
        in_dec+=POW(b,j)*digit_int[str[i]];
    return in_dec;
}
string convert_to(LL n,LL b)
{
    string str="";
    while(n)
    {
        str+=digit_char[n%b];
        n/=b;
    }
    if(str.size()==0)
        str="0";
    reverse(str.begin(),str.end());
    return str;

}
bool valid(string str,LL b)
{
    for(LL i=0;i<str.size();i++)
        if(digit_int[str[i]]>=b)
            return false;
    return true;
}
int main()
{
    LL i,j,x,y,cnt;
    string a,b;
    char ch;
    for(ch='0',j=0;ch<='9';ch++,j++)
        digit_int[ch]=j;
    for(ch='A',j=10;ch<='Z';ch++,j++)
        digit_int[ch]=j;


    while(cin>>num)
    {

        for(i=15;i>=2;i--)
        {

            if(valid(num,i))
            {
                a=num;
                cnt=0;
                while(true)
                {
                    b=a;
                    reverse(b.begin(),b.end());
                    //cout<<a<<" "<<b<<endl;
                    if(a==b)
                    {
                        if(i==2)
                        printf("%lld\n",cnt);
                        else
                        printf("%lld ",cnt);
                        break;
                    }
                    x=to_decimal(a,i);
                    y=to_decimal(b,i);
                    //cout<<x<<" "<<y<<endl;
                    a=convert_to(x+y,i);
                    cnt++;
                }
            }
            else
            {
                if(i==2)
                    printf("?\n");
                else
                    printf("? ");
            }
        }

    }
    return 0;
}
