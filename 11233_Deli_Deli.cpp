#include<stdio.h>
#include<string>
#include<map>
#include<iostream>
using namespace std;
string st1[21],st2[21];
string str;
int n;
bool isvowel(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        return true;
    return false;
}

bool ies()
{
    if(str[str.size()-1]=='y')
        if(!isvowel(str[str.size()-2]))
            return true;
    return false;
}

bool es(char ch)
{
    if(ch=='o' ||ch=='s' ||ch=='x')
        return true;
    else if(ch=='h')
    {
        ch=str[str.size()-2];
        if(ch=='c'||ch=='s')
            return true;
    }
    return false;
}
bool found()
{
    int i;
    for(i=0;i<n;i++)
        if(st1[i]==str)
        {
            str=st2[i];
            return true;
        }
    return false;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int m,i;
    while(scanf("%d %d",&n,&m)==2)
    {
        for(i=0;i<n;i++)
            cin>>st1[i]>>st2[i];

        for(i=0;i<m;i++)
        {
            cin>>str;
            if(found())
                cout<<str<<endl;
            else if(ies())
            {
                str.erase(str.size()-1,1);
                str+="ies";
                cout<<str<<endl;
            }
            else if(es(str[str.size()-1]))
            {
                str+="es";
                cout<<str<<endl;
            }
            else
            {
                str+="s";
                cout<<str<<endl;
            }
        }
    }
    return 0;
}
