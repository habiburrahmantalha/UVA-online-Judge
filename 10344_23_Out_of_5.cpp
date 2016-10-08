#include<stdio.h>
#include<algorithm>

using namespace std;

int a[10];
bool f;

void backtrack(int sum,int i)
{
    int j;
    if(i==4 && sum==23 )
    {
        f=true;
        return;
    }
    if(sum>200 || i==4)
        return;

    backtrack(sum+a[i+1],i+1);
    backtrack(sum-a[i+1],i+1);
    backtrack(sum*a[i+1],i+1);
}
int main()
{
    int i;
    while(1)
    {
        for(i=0;i<5;i++)
            scanf("%d",&a[i]);

        if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0 )
            break;

        f=false;
        sort(a,a+5);
        do
        {
            backtrack(a[0],0);
            if(f)
                break;
        }while(next_permutation(a,a+5));

        if(f)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}
