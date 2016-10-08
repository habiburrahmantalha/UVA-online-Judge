//Problem Type :
//Time : .076
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

int x[1010],n;
bool dream()
{
    for(int i=0;i<n;i++)
        if(x[i]<0 || x[i]>0)
            return false;

    return true;
}
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int tc,i,j;

    scanf("%d",&tc);
    while(tc--)
    {

        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&x[i]);
        sort(x,x+n,cmp);

        for(i=0;i<n;i++)
        {
            //for(int k=0;k<n;k++)
            //cout<<x[k]<<" ";
            //cout<<endl;

            j=i+1;

            while(x[i]>0 && j<n && x[j]>0)
            {

                x[j]--;
                x[i]--;
                j++;
            }
            if(x[i]>0)
            break;
            sort(x+i+1,x+n,cmp);
        }
        //*/

        if(!dream())
            printf("No\n");
        else
            printf("Yes\n");

    }
    return 0;
}
