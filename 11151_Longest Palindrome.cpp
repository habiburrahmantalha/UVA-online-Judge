#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

string s1,s2;

int LCS()
{
    int T[1010][1010],i,j;
    memset(T,0,sizeof(T));

    for(i=0;i<s1.size();i++)
    {
        for(j=0;j<s2.size();j++)
        {
            if(s1[i]==s2[j])
                T[i+1][j+1]=T[i][j]+1;
            else
                T[i+1][j+1]=max(T[i][j+1],T[i+1][j]);
        }
    }
    return T[s1.size()][s2.size()];
}



int main()
{
    int p,n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        getline(cin,s1);
        s2=s1;
        reverse(s2.begin(),s2.end());
        p=LCS();
        printf("%d\n",p);
    }
    return 0;
}
