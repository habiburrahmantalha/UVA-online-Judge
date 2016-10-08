#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int a[5],res[5];
    while(scanf("%d %d %d",a+0,a+1,a+2)==3 && a[0]+a[1]+a[2])
    {
        //printf("----->");
        sort(a,a+3);
        //3 equal
        if(a[0]==a[1] && a[0]==a[2])
        {
            if(a[0]==13)
            printf("*\n");
            else
            printf("%d %d %d\n",a[0]+1,a[0]+1,a[0]+1);
        }
        //3 unequal
        else if(a[0]!=a[1] && a[2]!=a[1] && a[0]!=a[2])
        printf("1 1 2\n");
        //1st 2 eq
        else if(a[0]==a[1])
        {

            if(a[2]==13)
            {
                res[2]=1;
                res[0]=res[1]=a[0]+1;
            }
            else
            {
                res[0]=res[1]=a[0];
                res[2]=a[2]+1;
            }
            sort(res,res+3);

            printf("%d %d %d\n",res[0],res[1],res[2]);

        }
        else if(a[1]==a[2])
        {
            if(a[1]==13)
            {
                if(a[0]+1==13)
                {
                    res[0]=1;
                    res[1]=res[2]=1;
                }
                else
                {
                    res[1]=res[2]=13;
                    res[0]=a[0]+1;
                }

            }
            else
            {
                if(a[0]+1==a[1])
                {
                    res[0]=a[1]+1;
                    res[1]=res[2]=a[1];
                }
                else
                {
                    res[0]=a[0]+1;
                    res[1]=res[2]=a[1];
                }
            }
            sort(res,res+3);
            printf("%d %d %d\n",res[0],res[1],res[2]);

        }

        //printf("%d %d %d",a[0],a[1],a[2]);
    }
    return 0;
}
