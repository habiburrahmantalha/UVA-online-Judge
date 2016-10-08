#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<ctype.h>
using namespace std;

int main()
{
    char mp[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
    string str;
    map<string,int> tn;
    map<string,int> :: iterator it;
    int i,j,tc,n;
    bool f=false,duplicate;
    scanf("%d",&tc);
    while(tc--)
    {
        if(f)
            printf("\n");
        duplicate=true;
        scanf("%d",&n);
        getchar();
        for(j=0;j<n;j++)
        {
            cin>>str;
            for(i=0;i<str.size();i++)
            {
                if(str[i]=='-')
                {
                    str.erase(i,1);
                    i--;
                }
                else if(isalpha(str[i]) && str[i]!='Q' && str[i]!='Z')
                    str[i]=mp[str[i]-'A']+'0';

            }
            str.insert(3,"-");
            tn[str]++;
        }
        for(it=tn.begin();it!=tn.end();it++)
        {
            if((*it).second>1)
            {
                duplicate=false;
                cout<<(*it).first<<" "<<(*it).second<<endl;
            }
        }
        if(duplicate)
            printf("No duplicates.\n");
        f=true;
        tn.clear();
    }
    return 0;
}
