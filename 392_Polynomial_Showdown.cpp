#include<stdio.h>
#include<algorithm>

using namespace std;

int x[10],p;
bool f;
void print(int i)
{
    if(x[i]==1 || x[i]==-1)
        printf("x^%d",p);
    else
        printf("%dx^%d",abs(x[i]),p);
}

void print_sign(int i)
{
    if(f)
    {
        if(x[i]>0)
            printf(" + ");
        else
            printf(" - ");
    }
    else
    {
        f=true;
        if(x[i]<0)
            printf("-");
    }
}
int main()
{
    int i;
    while(scanf("%d %d %d %d %d %d %d %d %d",&x[0],&x[1],&x[2],&x[3],&x[4],&x[5],&x[6],&x[7],&x[8])==9)
    {
        f=false;
        p=8;

        for(i=0;i<7;i++)
        {
            if(x[i]!=0)
            {
                print_sign(i);
                print(i);
            }
            p--;
        }

        if(x[7]!=0)
        {
            print_sign(7);
            if(x[7]==1 || x[7]==-1)
                printf("x");
            else
                printf("%dx",abs(x[7]));
        }

        if(x[8]!=0)
        {
            print_sign(8);
            printf("%d",abs(x[8]));
        }
        if(!f)
            printf("0");
        printf("\n");
    }
    return 0;
}
