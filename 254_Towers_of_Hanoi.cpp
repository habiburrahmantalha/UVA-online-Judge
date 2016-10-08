//Problem Type : Tower of honoi
//Time :
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

int m,cnt,a[5];
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

        a[from]--;
        a[to]++;
        cnt++;

        //printf("Move disk from pole %d to pole %d\n", from, to);
        if(cnt>=m)
        {
            printf("%d %d %d\n",a[1],a[2],a[3]);
            return;
        }
        if(cnt>=m)
    return;
        move(n - 1, via, to, from);

        if(cnt>=m)
            return;



    }
}

int main()
{
    int n;
    while(scanf("%d %d",&n,&m) && n+m)
    {
        cnt=0;
        a[1]=n;
        a[2]=a[3]=0;
        move(n,1,2,3);
        //cout<<a[1]<<a[2]<<a[3]<<endl;

    }

    return 0;
}
