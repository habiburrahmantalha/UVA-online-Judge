#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int i,j,k,len,check[30];
    char a[10001][21];
    i=0;
    memset(check,0,sizeof(check));
    while(1)
    {
        scanf("%s",a[i++]);
        if(a[i-1][0]=='#')
        break;
    }
    for(j=0;j<i;j++)
    {
        for(k=20;j>0;k--)
        if(isupper(a[j][k]))
        break;
        else
            a[j][k]='a';
    }
    for(j=0;j<21;j++)
    {
        for(k=0;k<i;k++)
        {
            if(isupper(a[k][j]) && check[a[k][j]-'A']==0)
            {
                printf("%c",a[k][j]);
                check[a[k][j]-'A']=1;
            }
        }
    }
    printf("\n");
    return 0;
}
