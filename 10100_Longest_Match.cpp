#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

string str;
map<string,int> mp;
int word_index,a[1000],b[1000],x[1000];

int word(int index)
{
    int i;
    string st="";
    for(i=0;i<str.size();i++)
    {
        if(isalnum(str[i]))
            st+=str[i];
        else
        {
            if(st.size()>0)
            {
                if(mp[st]==0)
                {
                    x[index++]=word_index;
                    mp[st]=word_index++;
                }
                else
                    x[index++]=mp[st];
                st="";
            }
        }
    }
    return index;
}
int LCS(int n,int m)
{
    int i,j,t[1000][1000];
    memset(t,0,sizeof(t));

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(a[i]==b[j])
                t[i+1][j+1]=t[i][j]+1;
            else
                t[i+1][j+1]=max(t[i+1][j],t[i][j+1]);
        }
    }
    return t[n][m];
}
int main()
{
    int t=1,n,m,match;
    bool s1,s2;
    while(getline(cin,str))
    {
        s1=true;
        s2=true;

        if(str.size()==0)
            s1=false;
        if(s1)
        {
            str+=" ";
            word_index=1;
            n=word(0);
            copy(x,x+n,a);
        }

        getline(cin,str);

        if(str.size()==0)
            s2=false;
        if(s2)
        {
            str+=" ";
            m=word(0);
            copy(x,x+m,b);
        }
        if(s1 && s2)
        {
            match=LCS(n,m);
            printf("%2d. Length of longest match: %d\n",t++,match);
        }
        else
            printf("%2d. Blank!\n",t++);

        mp.clear();
    }
    return 0;
}
