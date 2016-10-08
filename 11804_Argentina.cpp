#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;


struct player
{
    string name;
    int attack;
    int defence;
};

bool comp(player a,player b)
{
    if(a.attack==b.attack)
    {
        if(a.defence==b.defence)
            return a.name<b.name;
        else
            return a.defence<b.defence;
    }
    else
        return a.attack>b.attack;

}

bool comp1(player a,player b)
{
    return a.name<b.name;
}

int main()
{
    player A[11];
    int tc,t,i;
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        for(i=0;i<10;i++)
            cin>>A[i].name>>A[i].attack>>A[i].defence;
        sort(A,A+10,comp);

        sort(A,A+5,comp1);
        sort(A+5,A+10,comp1);
        //for(i=0;i<10;i++)
        //cout<<A[i].name<<A[i].attack<<A[i].defence<<endl;
        printf("Case %d:\n",t);
        cout<<"(";
        for(i=0;i<4;i++)
            cout<<A[i].name<<", ";
        cout<<A[i].name<<")"<<endl;

        cout<<"(";
        for(i=5;i<9;i++)
            cout<<A[i].name<<", ";
        cout<<A[i].name<<")"<<endl;
    }
    return 0;

}
