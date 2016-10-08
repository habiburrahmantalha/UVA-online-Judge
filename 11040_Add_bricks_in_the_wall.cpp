#include<stdio.h>
#include<string.h>

int main()
{
    int tc,i,j,k,x;
    int B[10][10];
    scanf("%d",&tc);
    while(tc--)
    {
        memset(B,0,sizeof(B));
        for(i=0;i<9;i+=2)
            for(j=0;j<=i;j+=2)
            scanf("%d",&B[i][j]);

        /*
        for(i=0;i<9;i++){
            for(j=0;j<=i;j++)
            printf("%d ",B[i][j]);
        printf("\n");}
        */

        for(i=2;i<9;i+=2)
        {
            for(j=0;j<=i-2;j+=2)
            {
                x=(B[i-2][j]-B[i][j]-B[i][j+2])/2;
                B[i][j+1]=x;
                B[i-1][j]=B[i][j]+x;
                B[i-1][j+1]=B[i][j+2]+x;
            }
        }

        for(i=0;i<9;i++){
            for(j=0;j<=i-1;j++)
            printf("%d ",B[i][j]);
        printf("%d\n",B[i][j]);
        }
    }
    return 0;
}
