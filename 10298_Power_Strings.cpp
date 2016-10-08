#include<stdio.h>
#include<string.h>

int l;
char s[1000010];
bool power(int k)
{
    int i,j;
    for(i=k;i<l;i+=k)
    {
        for(j=0;j<k;j++)
        if(s[j]!=s[i+j])
        return false;
    }

    return true;
}
int main()
{
    int i,j,k;
    while(scanf("%s",s))
    {
        if(s[0]=='.')
        break;

        l=strlen(s);
        for(i=l;i>=1;i--)
        {
            if(l%i==0)
            {
                //printf("%d\n",i);
                j=l/i;
                if(power(j))
                {

                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}
