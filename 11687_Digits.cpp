#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

string str;
int c;
string tochar(int x)
{
    string s="";
    while(x)
    {
        s+=(x%10)+'0';
        x/=10;
    }

    reverse(s.begin(),s.end());
    return s;
}
void digit(int x)
{
    str=tochar(x);

    int y=str.size();

    c++;
    if(x==y)
    return ;
    digit(y);

}
int main()
{
    string str;
    while(cin>>str && str!="END")
    {
        if(str=="1")
        {
            printf("1\n");
            continue;
        }
        c=1;
        digit(str.size());
        printf("%d\n",c);
    }
    return 0;
}
