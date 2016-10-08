#include<string>
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    string x,y;
    int i;
    while(1)
    {
        getline(cin,x);
        if(x=="DONE")
        break;
        for(i=0;i<x.size();i++)
        {
            if(!isalpha(x[i]))
            {
                x.erase(i,1);
                i--;
                continue;
            }
            if(isupper(x[i]))
            x[i]=tolower(x[i]);
        }
        y=x;
        reverse(y.begin(),y.end());
        if(x==y)
        printf("You won't be eaten!\n");
        else
        printf("Uh oh..\n");

    }
    return 0;
}
