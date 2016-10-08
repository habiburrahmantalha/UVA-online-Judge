#include<stdio.h>
#include<string.h>
int the9s(int sum)
{
    int y,res;
    if(sum<9)
    return 0;

    if(sum==9)
    return 1;

    y=sum;
    sum=0;
    while(y)
    {
        sum+=y%10;
        y/=10;
    }
    res = the9s(sum)+1;
    if(res==1)
    res=0;
    return res;
}



int main()
{
    char x[1001];
    int sum,i,res,len;
    while(scanf("%s",x))
    {
        if(strcmp(x,"0")==0)
        break;

        sum=0;
        len=strlen(x);
        for(i=0;i<len;i++)
        {
            sum+=x[i]-'0';
        }
        //printf("%d",sum);
        //*
        res=the9s(sum);
        if(res==0)
        printf("%s is not a multiple of 9.\n",x);
        else
        printf("%s is a multiple of 9 and has 9-degree %d.\n",x,res);
        //*/
    }
    return 0;
}
