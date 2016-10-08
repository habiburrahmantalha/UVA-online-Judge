#include<stdio.h>
/*
1-9=9*1
    10-99=90*2
    100-999=900*3
    1000-9999=9000*4
    10000-99999=90000*5
    100000-999999=900000*6
    */
long long res[100];
void precal()
{
    res[0]=0;
    res[1]=9;
    res[2]=res[1]+90*2;
    res[3]=res[2]+900*3;
    res[4]=res[3]+9000*4;
    res[5]=res[4]+90000*5;
    res[6]=res[5]+900000*6;
    res[7]=res[6]+9000000*7;
    res[8]=res[7]+90000000*8;
    res[9]=res[8]+900000000*9;
    res[10]=res[9]+9000000000*10;


}
void print(long long  i,long long  x,long long  k)
{
    long long p[100];
    while(x)
    {
        p[k--]=x%10;
        x/=10;
    }
    printf("%lld\n",p[i]);
}
int main()
{
    precal();
    long long n,x,y,z,i,j;
    while(scanf("%lld",&n)==1)
    {
        for(i=0; ;i++)
        if(n<res[i])
        break;

        n-=res[i-1];
        x=n/i;
        z=n%i;
        y=1;
        //printf("%lld %lld %lld ",x,y,z);
        for(j=1;j<i;j++)
        y*=10;
        y--;
        y+=x;

        if(z==0)
        printf("%lld\n",y%10);
        else
        print(z,y+1,i);
        printf("%lld %lld",y,z);
    }
    return 0;
}
