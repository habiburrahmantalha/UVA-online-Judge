#include<stdio.h>
#include<string.h>

int main()
{
    int tc,t,i,j,len,line,count;
    char str[510];
    bool f=false;
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        if(f)
            printf("\n");
        scanf("%d",&line);
        getchar();
        printf("Case %d:\n",t);
        for(i=0;i<line;i++)
        {
            gets(str);
            len=strlen(str);
            for(j=0;j<len;j++)
            {
                if(str[j]==' ')
                {
                    printf("%c",str[j]);
                    j++;
                    count=0;
                    while(str[j]==' ' && j<len)
                    {
                        j++;

                    }

                        j--;
                }
                else
                    printf("%c",str[j]);
            }
            printf("\n");
        f=true;
        }
    }
    return 0;
}
