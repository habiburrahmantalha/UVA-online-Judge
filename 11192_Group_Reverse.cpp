#include<string>
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    string str,temp,str2;
    int g,i,n;

    while(scanf("%d",&g) && g)
    {


        getline(cin,str);
        n=str.size()/g;
        str2="";
        for(i=1;i<str.size();i+=n)
        {
            temp=str.substr(i,n);
            reverse(temp.begin(),temp.end());
            str2+=temp;
            //cout<<temp<<endl;

        }
        cout<<str2<<endl;
    }
    return 0;
}
