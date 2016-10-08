#include<stdio.h>
#include<string.h>
int main()
{
    bool f[20010],B2;
    int i,j,n,B[110],t=1;
    while(scanf("%d",&n)==1)
    {
        B2=true;

        for(i=0;i<n;i++)
            scanf("%d",&B[i]);

        for(i=0;i<n-1;i++)
            if(B[i]< 1 || B[i]>=B[i+1])
            {
                B2=false;
                break;
            }

        if(B2){
            memset(f,false,sizeof(f));

            for(i=0;i<n;i++)
            {
                for(j=i;j<n;j++)
                    if(f[B[j]+B[i]]==1)
                    {

                        B2=false;
                        i=n;
                        break;
                    }
                    else
                        f[B[j]+B[i]]=1;
            }
        }
        if(B2)
            printf("Case #%d: It is a B2-Sequence.\n\n",t++);
        else
            printf("Case #%d: It is not a B2-Sequence.\n\n",t++);
    }
    return 0;
}
