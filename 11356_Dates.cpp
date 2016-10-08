#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;

map<string,int>mi;
map<string,int>mc;

void initialize()
{
    dm[]={31,28,31,30,31,30,31,31,30,31,30,31}
    mi["January"]=1;
    mi["February"]=2;
    mi["March"]=3;
    mi["April"]=4;
    mi["May"]=5;
    mi["June"]=6;
    mi["July"]=7;
    mi["August"]=8;
    mi["September"]=9;
    mi["October"]=10;
    mi["November"]=11;
    mi["December"]=12;

    mc[12]="January";
    mc[12]="February";
    mc[12]="March";
    mc[12]="April";
    mc[12]="May";
    mc[12]="June";
    mc[12]="July";
    mc[12]="August";
    mc[12]="September";
    mc[12]="October";
    mc[12]="November";
    mc[12]="December";
}
int main()
{
    int t=1,tc,d,a,y;
    char m[20],temp[20];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%[^-]",temp);
        y=atoi(temp);
        getchar();
        scanf("%[^-]",m);
        getchar();
        scanf("%d",&d);
        scanf("%d",&a);
        //cout<<y<<m<<d<<a<<endl;
    }
    return 0;
}
