#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;


int main()
{
    int tc,i,j,l;
    string str,s1,s2,s;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>str;
        for(i=0;i<str.size();i++)
        {
            l=str.size();
            if(l&1)
            l--;
            l/=2;
            s1=str.substr(0,l-i);
            s2=str.substr(l-i,l-i);
            //cout<<s1<<" "<<s2<<endl;
            if(s1==s2)
            {
                s1="";
                for(j=l-i+l-i;j<str.size();j++)
                s1+=str[j];
                s="";
                for(j=s1.size();j<s2.size();j++)
                s+=s2[j];

                //cout<<s1<<" "<<s<<endl;
                while(s.size()<8)
                s+=s2;
                for(j=0;j<8;j++)
                cout<<s[j];
                cout<<"..."<<endl;
                break;
            }
        }
    }
    return 0;
}
