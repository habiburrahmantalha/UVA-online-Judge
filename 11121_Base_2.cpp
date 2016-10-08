#include<stdio.h>
#include<string.h>
#include<math.h>

void base_2(int n)
{
    int res[100000];
    int r,in=0,i;
    if(n==0)
    res[in++]=0;
    while(n)
    {
        r=n%(-2);
        n/=(-2);
        if(r<0)
        {
            r+=2;
            n+=1;
        }
        res[in++]=r;
    }
    for(i=in-1;i>=0;i--)
    printf("%d",res[i]);
    printf("\n");
}
int main()
{
    int tc,t=1,n;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        printf("Case #%d: ",t++);
        base_2(n);
    }
    return 0;
}
