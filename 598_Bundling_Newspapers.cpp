#include<stdio.h>
#include<string.h>
#include<map>
#include<stdlib.h>
using namespace std;

int x[100],n,m,set;
char str[100][100],res[100][100];

void backtrack(int i,int k)
{
    int j,l;
    strcpy(res[k],str[i]);
    if(k==set)
    {
        for(j=1;j<k;j++)
            printf("%s, ",res[j]);
        printf("%s\n",res[j]);
        return;
    }
    for(l=i+1;l<m;l++)
    backtrack(l,k+1);
}

int main()
{
    int tc,i,j,k;
    char s[20];
    bool f=false;
    scanf("%d",&tc);
    gets(str[0]);
    gets(str[0]);
    while(tc--)
    {
        if(f)
            printf("\n");
        f=true;
        n=0;
        gets(str[0]);
        while(sscanf(str[0],"%s",s)==1)
        {
            if(s[0]=='*')
                x[n++]=13;
            else
            x[n++]=atoi(s);
        }
        gets(str[0]);
        m=0;
        while(gets(str[m]))
        {
            if(strlen(str[m])==0)
                break;
            m++;
        }
        for(i=0;i<n;i++)
        {
            if(x[i]==13)
                x[i]==m;
            set=x[i];
            printf("Size %d\n",x[i]);
            for(j=0;j<m;j++)
            backtrack(j,1);
            if(i+1!=n)
                printf("\n");
        }
    }
    return 0;
}
