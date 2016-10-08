#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    int i,j,tc=1;
    bool f;
    char c[30],c2[30];
    string x,y;
    scanf("%d",&tc);
    getchar();
    for(i=1;i<=tc;i++)
    {
        x.clear();
        y.clear();


        f=false;
        gets(c);
        gets(c2);
        x+=c;
        y+=c2;
        for(j=0;j<x.size();j++)
        if(x[j]==' ')
        {
            x.erase(j,1);
            j--;
            f=true;
        }
        if(f==false)
        {
            if(x==y)
            printf("Case %d: Yes\n",i);
            else
            printf("Case %d: Wrong Answer\n",i);

        }
        else
        {
            if(x==y)
            printf("Case %d: Output Format Error\n",i);
            else
            printf("Case %d: Wrong Answer\n",i);
        }

    }
    return 0;
}
