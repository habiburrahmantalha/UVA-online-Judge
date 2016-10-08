#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<time.h>
using namespace std;

int a[1000000],c;
void qsort(int left,int right)
{
    int i=left,j=right,mid;
    mid=(a[i]+a[j])/2;
    while(i<=j)
    {
        while(a[i]<mid)
            i++;
        while(a[j]>mid)
            j--;
        if(i<=j)
        {
            c++;
            swap(a[i],a[j]);
            i++;
            j--;
        }

    }
    if(left<j)
        qsort(left,j);
    if(i<right)
        qsort(i,right);
}

int main()
{
    int i,n;

    while(scanf("%d",&n) && n)
    {

    c=0;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    qsort(0,n-1);
    printf("%d\n",c);
    }


}
