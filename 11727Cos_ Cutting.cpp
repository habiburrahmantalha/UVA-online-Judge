#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    int n,x[3];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&x[0],&x[1],&x[2]);
        sort(x,x+3);
        printf("Case %d: %d\n",i+1,x[1]);
    }
    return 0;
}
