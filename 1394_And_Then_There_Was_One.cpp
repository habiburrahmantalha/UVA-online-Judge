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

int joseph(int n, int k)
{
    if(n == 1) return 0;
        return (joseph(n-1, k) + k)%n;
}

int main()
{
    int n,m,k,x,y;
    while(scanf("%d %d %d",&n,&k,&m) && n+k+m)
    {
        x = joseph(n,k)+1;
        k = k%n;
        if(k==0)
            k=n;

        y=(n+m-k+x)%n;
        if(y==0)
            y=n;
        printf("%d\n",y);

    }
    return 0;
}
