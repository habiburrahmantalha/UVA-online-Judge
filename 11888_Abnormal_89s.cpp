#include<stdio.h>
#include<string.h>

char s[200010];
int l;
bool palindrom(int i,int j)
{
    for(;i<=j;i++,j--)
    if(s[i]!=s[j])
    return false;

    return true;
}

bool alindrom()
{
    int i;
    for(i=0;i<l-1;i++)
    if(palindrom(0,i) && palindrom(i+1,l-1))
    return true;

    return false;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",s);
        l=strlen(s);

        if(alindrom())
        printf("alindrome\n");
        else if(palindrom(0,l-1))
        printf("palindrome\n");
        else
        printf("simple\n");
    }
    return 0;
}
