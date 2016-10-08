#include<stdio.h>
#include<string>
#include<iostream>
#include<ctype.h>
#include<algorithm>

using namespace std;

int sum_name(string name)
{
    int sum=0,i;
    for(i=0;i<name.size();i++)
    {
        if(isalpha(name[i]))
        {
            if(isupper(name[i]))
                sum+=name[i]-'A'+1;
            else
                sum+=name[i]-'a'+1;
        }
    }
    //printf("ns-%d\n",sum);
    return sum;
}
int digit_1(int x)
{
    int y=0;
    while(x)
    {
        y+=x%10;
        x/=10;
    }
    if(y<10)
    {
        //printf("d_1- %d\n",y);
        return y;
    }
    else
        digit_1(y);
}
double ratio (int a,int b)
{
    double res;
    if(a>9)
        a=digit_1(a);
    if(b>9)
        b=digit_1(b);

    if(b<a)
        swap(a,b);
    res=(double(a)/double(b))*100;
    return res;

}
int main()
{
    //freopen("in.txt","r",stdin);
    string name1,name2;

    double res;
    int sum1,sum2;

    while(getline(cin,name1))
    {
        getline(cin,name2);

        sum1=sum_name(name1);
        sum2=sum_name(name2);

        res=ratio(sum1,sum2);

        printf("%.2lf %\n",res);
    }
    return 0;
}
