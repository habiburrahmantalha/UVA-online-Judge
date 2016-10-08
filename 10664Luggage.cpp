#include<stdio.h>
#include<string.h>
int main()
{
    int m,i,j,x[210],sum,in,n,L[210];
    char ch;
    scanf("%d",&m);
    while(m--)
    {
        memset(L,0,sizeof(L));
        in=sum=0;
        while(1)
        {
            scanf("%d",&x[in++]);
            ch=getchar();
            sum+=x[in-1];
            if(ch==10)
            break;
        }
        if(sum&1)
        {
            printf("NO\n");
            continue;
        }
        L[0]=1;
        for(i=0;i<in;i++)
        {
            for(j=200;j>=0;j--)
            {
                if(L[j] && (j+x[i])<=200)
                {
                    L[j+x[i]]++;
                }
            }

        }
        if(L[sum/2]>=2)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
