#include<stdio.h>
#include<string.h>

int digit[10010][15];

void digit_count()
{
    int i,x,j;
    memset(digit,0,sizeof(digit));
    for(i=1;i<=10000;i++)
    {
        x=i;
        while(x)
        {
            digit[i][x%10]++;
            x/=10;
        }

    }
    for(i=2;i<=10000;i++)
    for(j=0;j<=9;j++)
        digit[i][j]+=digit[i-1][j];
}

int main()
{
    int tc,i,x;
    digit_count();
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&x);
        for(i=0;i<=8;i++)
        printf("%d ",digit[x][i]);
        printf("%d\n",digit[x][i]);
    }
    return 0;
}
