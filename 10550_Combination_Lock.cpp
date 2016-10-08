#include<stdio.h>

int main()
{
    int s,a,b,c,degree,temp;
    while(scanf("%d %d %d %d",&s,&a,&b,&c))
    {
        if(!s && !a && !b && !c)
            break;

        degree=720;

        temp=s-a;
        if(temp<0)
            temp+=40;
        degree+=temp*9;

        degree+=360;

        temp=b-a;
        if(temp<0)
            temp+=40;
        degree+=temp*9;

        temp=b-c;
        if(temp<0)
            temp+=40;
        degree+=temp*9;

        printf("%d\n",degree);

    }
    return 0;
}
