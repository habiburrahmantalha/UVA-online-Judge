//Problem Type : Bit,Ad hoc Unf
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

int N;
void print_bit(int n)
{
    int e=N,a;
    while(e--)
    {
        if(n&1)
        a=1;
        else
        a=0;
        n>>=1;
        printf("%d",a);
    }
    printf("\n");



}
int bit_1(int x,int i)
{
    for(int j=0;j<N;j++)
    {
        if(i!=j)
        x^=(1<<j);
    }
    return x;
}
void print()
{
    int lim=(1<<N)-1;
    int cnt=0;
    int x=0,y,i;
    bool f[lim+1];
    memset(f,false,sizeof(f));

    f[x]=true;
    while(cnt<=lim)
    {
        printf("%d\n",x);
        //print_bit(x);
        for(i=0;i<N;i++)
        {
            y=bit_1(x,i);
            if(!f[y])
            {
                f[y]=true;

                break;
            }
        }
        x=y;
        cnt++;

    }
    //printf("%d\n",cnt);
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&N);
        print();
    }
    return 0;
}
