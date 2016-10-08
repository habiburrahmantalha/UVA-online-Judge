#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;
int n;

char a[5][30]={ ".**.*.*****.*****..*",
                "**..*....*.**.*****.",
                "...................."};
map<string,int>mp;


void to_int()
{
    string z,str[2020];
    int i,j;

    for(i=0;i<3;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>z;
            str[j]+=z;
        }
    }
    for(i=0;i<n;i++)
    cout<<mp[str[i]];
    cout<<endl;
}
void to_brail()
{
    int i,j;
    char x[2020];
    scanf("%s",x);
    for(i=0;i<3;i++)
    {
        for(j=0;j<n-1;j++)
        printf("%c%c ",a[i][(x[j]-'0')*2],a[i][((x[j]-'0')*2)+1]);

        printf("%c%c\n",a[i][(x[j]-'0')*2],a[i][((x[j]-'0')*2)+1]);
    }
}
int main()
{

    mp["*....."]=1;
    mp["*.*..."]=2;
    mp["**...."]=3;
    mp["**.*.."]=4;
    mp["*..*.."]=5;
    mp["***..."]=6;
    mp["****.."]=7;
    mp["*.**.."]=8;
    mp[".**..."]=9;
    mp[".***.."]=0;

    char s[10];
    while(scanf("%d",&n)==1 && n)
    {
        scanf("%s",s);
        if(s[0]=='S')
        to_brail();
        else
        to_int();
    }
    return 0;
}
