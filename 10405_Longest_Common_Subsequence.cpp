#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;

int LCS(string s1,string s2)
{
    int t[1010][1010],i,j;
    memset(t,0,sizeof(t));
    for(i=0;i<s1.size();i++)
    {
        for(j=0;j<s2.size();j++)
        {
            if(s1[i]==s2[j])
                t[i+1][j+1]=t[i][j]+1;
            else
                t[i+1][j+1]=max(t[i][j+1],t[i+1][j]);
        }
    }
    return t[s1.size()][s2.size()];
}

int main()
{
    string str1,str2;
    int n;
    while(getline(cin,str1))
    {
        getline(cin,str2);
        n=LCS(str1,str2);
        printf("%d\n",n);
    }
    return 0;
}
