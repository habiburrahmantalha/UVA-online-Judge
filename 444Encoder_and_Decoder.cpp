#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<map>
#include<algorithm>
#include<ctype.h>
#include<stdlib.h>
using namespace std;

map<char,string> me;
map<string,char> md;

string rev(int i)
{
    string j = "";
    while(i)
    {
        j+=(i%10+48);
        i/=10;
    }
    return j;
}

string to_str(int i)
{
    string j;
    j=rev(i);
    reverse(j.begin(),j.end());
    return j;
}
void encode_decode()
{
    int i,j;
    char c;
    me[' ']="23";
    me['!']="33";
    me[',']="44";
    me['.']="64";
    me[':']="85";
    me[';']="95";
    me['?']="36";

    md["32"]=' ';
    md["33"]='!';
    md["44"]=',';
    md["46"]='.';
    md["58"]=':';
    md["59"]=';';
    md["63"]='?';

    i=65;
    for(c='A';c<='Z';c++,i++)
    {

        me[c]=rev(i);
        md[to_str(i)]=c;
    }
    i=97;
    for(c='a';c<='z';c++,i++)
    {

        me[c]=rev(i);
        md[to_str(i)]=c;
    }
}

void encode(string str)
{
    for(int i=0;i<str.size();i++)
        cout<<me[str[i]];
    printf("\n");
}

void decode(string str)
{
    int i,x;
    string temp;
    for(i=0;i<str.size();i++)
    {
        temp=str.substr(i,3);
        x=(temp[0]-'0')*100+(temp[1]-'0')*10+(temp[2]-'0');
        if(x<123)
        {
            cout<<md[temp];
            i+=2;
        }
        else
        {
            temp=str.substr(i,2);
            cout<<md[temp];
            i++;
        }
    }
    printf("\n");
}

int main()
{
    encode_decode();
    string str;
    while(getline(cin,str))
    {
        reverse(str.begin(),str.end());
        if(isdigit(str[0]))
        decode(str);
        else
        encode(str);
    }
    return 0;
}
