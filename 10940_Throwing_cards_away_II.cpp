#include<stdio.h>
#include<queue>
using namespace std;

int card[5000100];
void throw_card()
{
    int n=4,i,j;
    card[1]=1;card[2]=2;
    for(i=3;i<=500000;i++)
    {
        for(j=2;j<=n && i<=500000;j+=2)
            card[i++]=j;
        n*=2;
        i--;
    }
}
int main()
{
    throw_card();
    int n;
    while(scanf("%d",&n) && n)
        printf("%d\n",card[n]);
    return 0;
}

