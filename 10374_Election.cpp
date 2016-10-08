#include<stdio.h>
#include<map>
#include<string.h>
#include<string>

using namespace std;

int main()
{
    int tc,i,n,mx;
    string str;
    bool f=false,tie;
    char x[100],y[100];
    map<string,string> mp1;
    map<string,int>mp2;
    map<string,int> :: iterator it;
    scanf("%d",&tc);

    while(tc--)
    {
        if(f)
        printf("\n");
        f=true;
        scanf("%d",&n);
        gets(x);
        for(i=0;i<n;i++)
        {
            gets(x);
            gets(y);
            mp1[x]=y;
        }
        scanf("%d",&n);
        gets(x);
        for(i=0;i<n;i++)
        {
            gets(x);
            if(mp1[x]!="")
            mp2[x]++;
        }
        mx=0;
        str="";
        tie=false;
        for(it=mp2.begin();it!=mp2.end();it++)
        {
            if(mx==it->second)
            {
                tie=true;
                break;
            }
            if(mx<it->second)
            {
                mx=it->second;
                str=it->first;
            }

        }
        if(tie)
        printf("tie\n");
        else
        printf("%s\n",mp1[str].c_str());
        mp1.clear();
        mp2.clear();

    }
    return 0;
}
