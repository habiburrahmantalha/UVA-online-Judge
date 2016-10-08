#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
map<string,string>mp;

void store(char s[])
{
    string str;
    int i;
    for(i=0;s[i]!=0;i++)
    {
        if(isalpha(s[i]))
        str+=s[i];
    }
    sort(str.begin(),str.end());
    mp[s]=str;
}
int main()
{
    int tc,i,j;
    bool f=false;
    char x[1000];
    scanf("%d",&tc);
    gets(x);
    gets(x);
    while(tc--)
    {
        if(f)
        printf("\n");
        f=true;

        while(gets(x))
        {

            if(strlen(x)==0)
            break;
            store(x);
        }
        map<string,string> :: iterator it,it2;

        for(it=mp.begin();it!=mp.end();it++)
        {
            it2=it;
            it2++;
            for(;it2!=mp.end();it2++)
            {
                if(it->second==it2->second)
                printf("%s = %s\n",it->first.c_str(),it2->first.c_str());
            }
        }
        /*
        for(i=0;i<in;i++)
        {
            for(j=i+1;j<in;j++)
            {
                if(mp[x[i]]==mp[x[j]])
                printf("%s = %s\n",x[i],x[j]);
            }
        }
        */
        mp.clear();
    }
}
