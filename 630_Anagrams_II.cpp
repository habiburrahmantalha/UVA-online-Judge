#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int T,i,n;
    bool f=false;
    map<string,vector<string> > mv;
    string str,temp;
    scanf("%d",&T);

    while(T--)
    {
        if(f)
            printf("\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>str;
            temp=str;
            sort(temp.begin(),temp.end());
            mv[temp].push_back(str);
        }
        while(cin>>str && str!="END")
        {
            temp=str;
            sort(temp.begin(),temp.end());
            printf("Anagrams for: %s\n",str.c_str());
            for(i=0;i<mv[temp].size();i++)
            {
                printf("%3d) %s\n",i+1,mv[temp][i].c_str());
            }
            if(i==0)
                printf("No anagrams for: %s\n",str.c_str());
        }
        f=true;
        mv.clear();
    }
    return 0;
}
