#include<string.h>
#include<stdio.h>
int res[50010][4];
void precal()
{
    int i,j,k,a,c,b;
    for(i=0;i*i<=50000;i++)
    {
        a=i*i;
        for(j=i;a+j*j<=50000;j++)
        {
            b=j*j;
            for(k=j;a+b+k*k<=50000;k++)
            {
                c=k*k;
                if(!res[a+b+c][0])
                {
                    res[a+b+c][0]=1;
                    res[a+b+c][1]=i;
                    res[a+b+c][2]=j;
                    res[a+b+c][3]=k;
                }
            }

        }
    }
}
int main()
{
    //freopen("out.txt","w",stdout);
    memset(res,0,sizeof(res));
    precal();
    int n,tc;
    //scanf("%d",&tc);
    n=100;
    while(n--)
    {
        //scanf("%d",&n);

        if(res[n][0])
        printf("%d %d %d\n",res[n][1],res[n][2],res[n][3]);
        else
        printf("-1\n");
    }
    return 0;
}
