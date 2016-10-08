#include<stdio.h>

void print_4(int i)
{
    int j,k;
    for(j=i;j<i+4;j++)
    for(k=j+1;k<i+4;k++)
    printf("%d %d\n",j,k);
}
void print_6(int i)
{
    int j,k,a=3,b,c=3;
    for(j=i;j<i+6;j++)
    {
        if(j&1)
        {
            for(k=j+1,b=1;b<=a;k++,b++)
            printf("%d %d\n",j,k);
            a--;
        }
        else
        {
            for(k=j+c,b=1;b<=a;k++,b++)
            printf("%d %d\n",j,k);
            c--;
        }
    }
}
int main()
{
    int n,i;
    while(scanf("%d",&n) && n)
    {
        if(n&1 || n<4)
        printf("Impossible\n");
        else
        {
            if(n%4==0)
            {
                printf("%d\n",n*6/4);
                for(i=1;i<=n;i+=4)
                print_4(i);
                //printf("\n");
            }
            else
            {
                printf("%d\n",9+(n-6)*6/4);
                print_6(1);
                for(i=7;i<=n;i+=4)
                print_4(i);
                //printf("\n");
            }

        }
    }
    return 0;
}
