#include<stdio.h>
#include<math.h>
long long H(int n){

    long long res = 0,m,i;
    m=sqrt(n);
    for(i = 1; i <=m; i=i+1 )
    {
        //printf("%d ",m);
        res = (res + m);

    }
    res+=;
    return res;
}

int main()
{
    int tc,n;
    long long res;
    scanf("%d",&tc);

    while(tc--)
    //for(n=0;n<100;n++)
    {
        scanf("%d",&n);
        res=H(n);
        printf("%lld\n",res);
    }
    return 0;
}
