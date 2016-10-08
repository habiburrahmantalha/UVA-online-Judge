#include<stdio.h>


int cal(int a,int b)
{
    int i,max=0,count;

    for(i=a;i<=b;i++)
    {
        a=i;
        count=0;
        while(a!=1)
        {
            if(a&1)
            a=3*a+1;
            else
            a=a/2;
            count++;
        }
        //printf("%d %d\n",i,max);
        if(max<count)
        max=count;
    }
    return max+1;

}
int main()
{
    int i,j;
    while(scanf("%d %d",&i,&j)==2)
    {
        if(i<j)
        printf("%d %d %d\n",i,j,cal(i,j));
        else
        printf("%d %d %d\n",i,j,cal(j,i));
    }
    return 0;

}
