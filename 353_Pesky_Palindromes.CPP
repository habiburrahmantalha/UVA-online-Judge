#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

bool ispalindrom(string a)
{
    string b;
    b=a;
    reverse(a.begin(),a.end());
    if(a==b)
        return true;
    else
        return false;
}
int main()
{
    string x,temp;
    int i,j;
    set<string> st;
    while(getline(cin,x))
    {
        st.clear();
        for(i=0;i<x.size();i++)
        {
            for(j=1;j<x.size()-i+1;j++)
            {
                temp=x.substr(i,j);
                //cout<<temp<<endl;
                if(ispalindrom(temp))
                    st.insert(temp);
            }
        }
        printf("The string '%s' contains %d palindromes.\n",x.c_str(),st.size());
    }
    return 0;
}
