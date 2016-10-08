#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
#include<iostream>
#include<algorithm>

string str;

bool ispalindrom(int s,int e)
{
    for(int i=s,j=e-1;i<j;i++,j--)
    if(str[i]!=str[j])
    return false;
    return true;
}
int main()
{
    string temp;
    int i,l;
    while(cin>>str)
    {
        l=str.size();
        for(i=0;i<l;i++)
        {
            if(str[l-1]==str[i])
            {
                if(ispalindrom(i,l))
                break;
            }
        }
        temp=str.substr(0,i);
        reverse(temp.begin(),temp.end());
        str+=temp;
        cout<<str<<endl;
    }
    return 0;

}
