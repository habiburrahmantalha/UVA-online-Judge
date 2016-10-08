#include<stdio.h>
#include<string.h>

int f[1000];
void failure_function(char pattern[])
{
    int i,j,m;
    m=strlen(pattern);

    f[0]=f[1]=0;
    for(i=2;i<=m;i++)
    {
        j=f[i-1];
        for(;;)
        {
            if(pattern[j]==pattern[i-1])
            {
                f[i]=j+1;
                break;
            }
            if(j==0)
            {
                f[i]=0;
                break;
            }
            j=f[j];
        }
    }
}
bool KMP(char text[],char pattern[])
{
    int i,j,m,n;
    n=strlen(text);
    m=strlen(pattern);
    failure_function(pattern);

    i=0; //initial state of automaton, empty string
    j=0; //first char ot text

    for(;;)
    {
        if(j==n)
            break;

        if(text[j]==pattern[i])
        {
            i++;
            j++;
            if(i==m)
                return true; // match found
        }
        else if(i>0)
            i=f[i];
        else
            j++;
    }
    return false;
}

int main()
{
    int tc,n;
    char text[100010],pattern[1010];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",text);
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",pattern);
            if(KMP(text,pattern))
                printf("y\n");
            else
                printf("n\n");
        }
    }
    return 0;
}
