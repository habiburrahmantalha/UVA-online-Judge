#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

string str;
int order(char x)
{
    if(x=='B')
    return 0;
    else if(x=='U')
    return 1;
    else if(x=='S')
    return 2;
    else if(x=='P')
    return 3;
    else if(x=='F')
    return 4;
    else if(x=='T')
    return 5;
    else if(x=='M')
    return 6;
}
bool error()
{
    int i,c=0;
    for(i=0;i<str.size()-1;i++)
    {
        if(str[i]==str[i+1])
        c++;
        else
        c=0;
        if(order(str[i])<order(str[i+1]))
        return true;
        if(c==9)
        return true;


    }
    return false;
}

int main()
{
    int tc,res,i;

    scanf("%d",&tc);
    while(tc--)
    {
        cin>>str;

        if(error())
        reverse(str.begin(),str.end());

        if(error())
        printf("error\n");
        else
        {
            res=0;
            for(i=str.size()-1;i>=0;i--)
            {
                if(str[i]=='B')
                res+=1;
                else if(str[i]=='U')
                res+=10;
                else if(str[i]=='S')
                res+=100;
                else if(str[i]=='P')
                res+=1000;
                else if(str[i]=='F')
                res+=10000;
                else if(str[i]=='T')
                res+=100000;
                else if(str[i]=='M')
                res+=1000000;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
