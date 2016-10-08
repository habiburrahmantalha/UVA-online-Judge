#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int i,j,k,len,check[26]={0};
    char temp[100],a[10000][21];
    i=0;
    while(1)
    {
        scanf("%s",temp);
        if(temp[0]=='#')
        break;
        len=strlen(temp);
        for(j=0;j<len;j++)
        a[i][j]=temp[j];

        while(j!=21)
        a[i][j++]='a';
        i++;
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
