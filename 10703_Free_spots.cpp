#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    int w,h,n,i,j,k,x1,x2,y1,y2,board[510][510],count,res;
    while(scanf("%d %d %d",&w,&h,&n) )
    {
        if(w==0 && h==0 && n==0)
            break;
        memset(board,0,sizeof(board));

        count=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(x1>x2)
                swap(x2,x1);
            if(y1>y2)
                swap(y1,y2);

            for(j=x1;j<=x2;j++)
            {
                for(k=y1;k<=y2;k++)
                {
                    if(board[j][k]==0)
                    {
                        count++;
                        board[j][k]=1;
                    }
                }
            }
        }
    res=w*h-count;
    if(res==0)
        printf("There is no empty spots.\n");
    else if(res==1)
        printf("There is one empty spot.\n");
    else
    printf("There are %d empty spots.\n",res);
    }
    return 0;
}
