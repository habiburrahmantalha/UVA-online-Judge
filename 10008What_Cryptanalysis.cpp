#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>

using namespace std;


int main()
{

    int tc,count=0,y[26]={0};
    char ch;
    char x[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    scanf("%d\n",&tc);
    while(tc--)
    {
        while(ch=getchar())
        {
            if(ch==10)
            break;
            if(isalpha(ch))
            {
                if(islower(ch))
                y[toupper(ch)-'A']++;
                else
                y[ch-'A']++;
            }
        }
    }

    for(int i=0;i<26;i++)
    for(int j=0;j<26-1;j++)
    {
        if(y[j+1]>y[j])
        {
            swap(y[j+1],y[j]);
            swap(x[j+1],x[j]);
        }
    }

    for(int i=0;i<26;i++)
    if(y[i])
    {
        printf("%c %d\n",x[i],y[i]);
    }
    return 0;
}
