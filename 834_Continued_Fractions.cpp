#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int x,y,z;
    bool f;
    while(scanf("%d %d",&x,&y)==2)
    {
        z=x/y;
        printf("[%d;",z);
        f=false;
        while(1)
        {
            x=x-y*z;
            swap(x,y);
            if(y==0)
                break;
            if(f)
                printf(",");
            z=x/y;
            printf("%d",z);
            f=true;
        }
        printf("]\n");
    }
    return 0;
}
