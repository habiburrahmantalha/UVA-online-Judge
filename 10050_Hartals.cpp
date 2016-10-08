#include<stdio.h>
#include<string.h>
int H[3650+1],day,p,x;

int main()
{
    int tc,i,j,res;
    scanf("%d",&tc);
    while(tc--)
    {
        res=0;
        memset(H,0,sizeof(H));
        scanf("%d",&day);
        scanf("%d",&p);
        for(i=0;i<p;i++)
        {
            scanf("%d",&x);
            for(j=x;j<=day;j+=x)
                H[j]=1;
        }
        for(i=6;i<=day;i+=7)
            H[i]=H[i+1]=0;
        for(i=0;i<=day;i++)
            if(H[i]==1)
            res++;
        printf("%d\n",res);
    }
    return 0;
}
