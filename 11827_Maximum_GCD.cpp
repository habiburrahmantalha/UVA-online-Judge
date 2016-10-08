#include<stdio.h>
#include<sstream>
#include<iostream>
using namespace std;

int GCD(int a,int b)
{
    if(a==0)
        return b;
    if(a>b)
        GCD(a-b,b);
    else
        GCD(b-a,a);
}

int main()
{
    int i,j,k,mx,y,x[110],tc;
    char a[10000];
    stringstream ss;
    char ch;
    scanf("%d",&tc);
    gets(a);
    while(tc--)
    {
        ch=' ';
        gets(a);
        ss<<a;
        i=0;
        while(ss>>x[i])
            i++;

        mx=0;
        for(j=0;j<i;j++)
            for(k=j+1;k<i;k++)
            {
                y=GCD(x[j],x[k]);
                if(mx<y)
                    mx=y;
            }
        printf("%d\n",mx);
        ss.clear();
    }
    return 0;
}
