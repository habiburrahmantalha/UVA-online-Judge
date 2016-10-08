#include<stdio.h>
#include<string.h>

int number,it,H[100010]={0};
bool mark[1000];

bool happy(int x)
{
    int d,n=0;
    while(x)
    {
        d=x%10;
        x/=10;
        n+=(d*d);
    }
    it++;
    if(n==1)
    return true;
    else if(mark[n])
    return false;
    else
    {
        mark[n]=1;;
        happy(n);
    }
}

void happynumber()
{
    int i;
    H[1]=1;
    for(i=7;i<100000;i++)
    {
        memset(mark,0,sizeof(mark));
        if(happy(i))
        {
            H[i]=it;
            it=1;
        }
        else
        it=1;
    }
}

int main()
{
    it=1;
    bool f=false;
    happynumber();
    int i,a,b;

    while(scanf("%d %d",&a,&b)==2)
    {
        if(f==true)
        printf("\n");
        for(i=a;i<=b;i++)
        if(H[i])
        printf("%d %d\n",i,H[i]);
        f=true;

    }

    return 0;
}
