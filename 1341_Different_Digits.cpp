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
#define N 65537
int D[N+1];
int D_1[]={ 1,11,111,1111,11111,111111,1111111,11111111,
            2,22,222,2222,22222,222222,2222222,22222222,
            3,33,333,3333,33333,333333,3333333,33333333,
            4,44,444,4444,44444,444444,4444444,44444444,
            5,55,555,5555,55555,555555,5555555,55555555,
            6,66,666,6666,66666,666666,6666666,66666666,
            7,77,777,7777,77777,777777,7777777,77777777,
            8,88,888,8888,88888,888888,8888888,88888888,
            9,99,999,9999,99999,999999,9999999,99999999};
bool D_1_mult(int x)
{

    for(int i=0;i<72;i++)
    {
        if(D_1[i]>x && D_1[i]%x==0)
        return true;

    }
    return false;
}
int Digit(int x)
{
    int f[10];
    memset(f,false,sizeof(f));
    int c=0;
    while(x)
    {
        if(!f[x%10])
        {
            c++;
            f[x%10]=true;
        }
        x/=10;
    }
    return c;

}
void precal()
{
    int i,j,d,mx,mxi;
    for(i=1;i<N;i++)
    {
        mx=11;
        if(D_1_mult(i))
        {
            D[i]=i;
            continue;
        }
        for(j=1;i*j<10000000;j++)
        {
            d=Digit(i*j);
            if(d==2)
            {
                mx=2;
                mxi=i*j;
                break;
            }
            if(mx>d)
            {
                mx=d;
                mxi=i*j;
            }
        }
        D[i]=mxi;
    }

}

int main()
{
    cout<<D_1[71];
    precal();
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        printf("%d\n",D[n]);

    }
    return 0;
}
