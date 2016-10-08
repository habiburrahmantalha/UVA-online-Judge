#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int print(string x)
{
    int p,res=0,i;
    p=6;
    for(i=2;i<6;i++)
    {
        if(x[i]=='o')
        {
            res+=pow(2,p);
            p--;
        }
        else
        {
            p--;
        }

    }

    for(i=7;i<11;i++)
    {
        if(x[i]=='o')
        {
            res+=pow(2,p);
            p--;
        }
        else
        {
            p--;
        }

    }
    //printf("%d ",res);
    return res;
}

int main()
{
    string str;
    bool start=false;
    while(1)
    {
        getline ( cin, str );
        if ( start == true && str == "___________" )
        break;
        else if ( str == "___________")
        start = true;
        else
        {
            //getline(cin,str);
            printf("%c",print(str));
        }
    }
    return 0;
}
