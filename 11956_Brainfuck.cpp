#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
    int tc,t=1,i,p;
    unsigned char mem[110];

    string str;
    scanf("%d",&tc);

    while(tc--)
    {
        cin>>str;
        memset(mem,0,sizeof(mem));
        p=0;
        for(i=0;i<str.size();i++)
        {
            if(str[i]=='>')
            p=(100+p+1)%100;
            if(str[i]=='<')
            p=(100+p-1)%100;
            if(str[i]=='+')
            mem[p]=(256+mem[p]+1)%256;
            if(str[i]=='-')
            mem[p]=(256+mem[p]-1)%256;

        }
        printf("Case %d:",t++);
        for(i=0;i<100;i++)
        printf(" %02X",mem[i]);
        printf("\n");
    }
    return 0;
}
