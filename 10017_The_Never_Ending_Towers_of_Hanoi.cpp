//Problem Type :    Tower of Hanoi
//Time :    0.028
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)


int m,cnt,n;
vector<int>v[5];

void print()
{
    int i;
    if(v[1].size())
    printf("A=>  ");
    else
    printf("A=>");

    for(i=0;i<v[1].size();i++)
    printf(" %d",v[1][i]);
    printf("\n");

    if(v[3].size())
    printf("B=>  ");
    else
    printf("B=>");

    for(i=0;i<v[3].size();i++)
    printf(" %d",v[3][i]);
    printf("\n");


    if(v[2].size())
    printf("C=>  ");
    else
    printf("C=>");

    for(i=0;i<v[2].size();i++)
    printf(" %d",v[2][i]);
    printf("\n");

    printf("\n");

}
void move(int n,int from,int to,int via)
{
    if(cnt>=m)
    return;

    if(n>0)
    {
        if(cnt>=m)
        return;
        move(n - 1, from, via, to);

        if(cnt>=m)
            return;

        v[to].push_back(v[from].back());
        v[from].pop_back();

        cnt++;
        print();
        if(cnt>=m)
            return;

        move(n - 1, via, to, from);

        if(cnt>=m)
            return;
    }
}

void initialize()
{
    int i;
    cnt=0;
    v[1].clear();
    v[2].clear();
    v[3].clear();
    for(i=n;i>=1;i--)
    v[1].push_back(i);
}

int main()
{
    int t=1;
    while(scanf("%d %d",&n,&m) && n+m)
    {
        printf("Problem #%d\n\n",t++);

        initialize();

        print();

        move(n,1,2,3);

    }
    return 0;
}
