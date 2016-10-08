#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    int tc,a[4];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
        sort(a,a+4);
        if(a[0]==a[1] && a[2]==a[3])
        {
            if(a[0]==a[3])
                printf("square\n");
            else
                printf("rectangle\n");
        }
        else if(a[0]+a[1]+a[2]>a[3])
            printf("quadrangle\n");
        else
            printf("banana\n");
    }
    return 0;
}
