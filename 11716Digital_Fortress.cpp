#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    //freopen("in.txt","r",stdin);
    int tc,len,i,j;
    double n;
    char x[10010];
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        gets(x);
        len=strlen(x);
        n=sqrt(len);
        if(n==int(n))
        {
            for(i=0;i<n;i++)
            {
                for(j=i;j<len;j+=n)
                {
                    printf("%c",x[j]);

                }

            }
            printf("\n");
        }
        else
        printf("INVALID\n");
    }
    return 0;
}
