#include<stdio.h>

int main()
{
    int n,x,count,i;
    char ans[]={"ABCDE"},ch;
    while(scanf("%d",&n) &&n)
    {
        while(n--)
        {
            count=0;
            for(i=0;i<5;i++)
            {
                scanf("%d",&x);
                if(x<=127)
                {
                    count++;
                    ch=i;
                }
            }
            if(count==1)
            printf("%c\n",ans[ch]);
            else
            printf("*\n");
        }
    }
    return 0;
}
