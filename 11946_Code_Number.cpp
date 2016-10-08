#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string>
#include<string.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    char decode[]={"OIZEASGTBP"};
    string x;
    int tc;
    bool f2=false;

    scanf("%d\n",&tc);

    while(tc--)
    {
        if(f2)
            printf("\n");
        while(getline(cin,x))
        {
            if(x.size()==0)
                break;
            for(int i=0;i<x.size();i++)
            {
                if(isdigit(x[i]))
                    printf("%c",decode[x[i]-'0']);
                else
                    printf("%c",x[i]);
            }
            printf("\n");
        }
        f2=true;
    }
    return 0;
}
