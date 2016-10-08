#include<stdio.h>
#include<string.h>

int main()
{
    int S,B,i,j,a,L,R,N_L[100010],N_R[100010];
    bool f;
    while(scanf("%d %d",&S,&B)==2 && S+B)
    {
        for(i=1;i<=S;i++)
        N_R[i]=i+1;
        for(i=1;i<=S;i++)
        N_L[i]=i-1;

        for(i=0;i<B;i++)
        {
            scanf("%d %d",&L,&R);
            N_R[N_L[L]]=N_R[R];
            N_L[N_R[R]]=N_L[L];
            if(N_L[L]==0)
            printf("* ");
            else
            printf("%d ",N_L[L]);

            if(N_R[R]==S+1)
            printf("*\n");
            else
            printf("%d\n",N_R[R]);
            /*
            for(j=L;j<=R;j++)
            {
                if(N_R[j])
                j=N_R[j];
                else
                {
                    N_R[j]=R;
                    N_L[j]=L;
                }
            }

            f=false;
            for(a=L;a>0;a--)
            if(N_L[a])
            {
                a=N_L[a];
            }
            else
            {
                f=true;
                printf("%d ",a);
                break;
            }
            if(!f)
            printf("* ");

            f=false;
            for(a=R;a<=S;a++)
            if(N_R[a])
            {
                a=N_R[a];
            }
            else
            {
                f=true;
                printf("%d\n",a);
                break;
            }
            if(!f)
            printf("*\n");
            */
        }
        printf("-\n");
    }
    return 0;
}
