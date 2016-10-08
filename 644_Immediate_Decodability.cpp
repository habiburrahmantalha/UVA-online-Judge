#include<stdio.h>
#include<string>
#include<map>
#include<iostream>
using namespace std;
int main()
{
    string N,temp;
    bool f=false;
    map<string,int> mp;
    int i,s=1;

    while(cin>>N)
    {
        if(N=="9")
        {
            if(f)
                printf("Set %d is not immediately decodable\n",s++);
            else
                printf("Set %d is immediately decodable\n",s++);
            f=false;
            mp.clear();
        }
        else
        {
            if(f)
                continue;
            for(i=1;i<=N.size();i++)
            {
                temp=N.substr(0,i);

                if(mp[temp]==1)
                {
                    f=true;
                    break;
                }
            }
            if(f)
                continue;
            mp[N]=1;

        }
    }
    return 0;
}
