#include<stdio.h>
#include<sstream>
#include<string>
#include<iostream>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;

map<char,int>to_dec;

char to_hex[]={"0123456789ABCDEF"};

void convert_hex(int x)
{

    string hex="";
    while(x)
    {
        hex+=to_hex[x%16];
        x/=16;
    }
    hex+="x0";
    reverse(hex.begin(),hex.end());
    cout<<hex<<endl;
}
void convert_dec(string str)
{
    int i,dec_num=0;
    for(i=2;i<str.size();i++)
        if(isdigit(str[i]))
            dec_num+=pow(16,str.size()-i-1)*(str[i]-'0');
        else
            dec_num+=pow(16,str.size()-i-1)*to_dec[str[i]];
    printf("%d\n",dec_num);
}
int main()
{

    to_dec['A']=10;
    to_dec['B']=11;
    to_dec['C']=12;
    to_dec['D']=13;
    to_dec['E']=14;
    to_dec['F']=15;
    string str;
    int num;
    while(cin>>str)
    {
        if(str[1]=='x')
            convert_dec(str);
        else
        {
            stringstream ss(str);
            ss>>num;
            if(num<0)
                break;
            convert_hex(num);
        }
    }
    return 0;
}

