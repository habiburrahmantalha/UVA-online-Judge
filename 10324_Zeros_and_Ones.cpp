#include<stdio.h>
#include<string.h>

int a,b;
char x[1000010];
int sum[1000010];
void cal()
{
    int i,j;
    sum[0]=x[0]-'0';
    for(i=1;x[i];i++)
        sum[i]=x[i]-'0'+sum[i-1];
    //for(j=0;j<i;j++)
    //printf("%d ",sum[j]);
}
bool same()
{
    if(sum[b]-sum[a-1]==0 || sum[b]-sum[a-1]==b-a+1)
    return true;
    return false;
}
int main()
{
    int q,t=1;
    while(scanf("%s",x)==1)
    {
        cal();
        scanf("%d",&q);
        printf("Case %d:\n",t++);
        while(q--)
        {
            scanf("%d %d",&a,&b);
            if(a>b)
            {
                b^=a;
                a^=b;
                b^=a;
            }

            if(same())
            printf("Yes\n");
            else
            printf("No\n");
        }
    }
    return 0;
}
