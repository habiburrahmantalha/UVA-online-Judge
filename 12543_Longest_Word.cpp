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
#include<sstream>
using namespace std;
#define PI 2 * acos (0.0)

int main()
{
    string str,s="";
    int i,k=0;
    while(cin>>str && str!="E-N-D")
    {
        for(i=0;i<str.length();i++)
        if(!isalpha(str[i]) && str[i]!='-')
        str[i]=' ';
        stringstream ss(str);
        while(ss>>str)
        if(str.size()>k)
        {
            k=str.size();
            s=str;
        }
    }
    for(i=0;i<s.length();i++)
    if(isalpha(s[i]))
    s[i]=tolower(s[i]);
    cout<<s<<endl;
    return 0;
}
