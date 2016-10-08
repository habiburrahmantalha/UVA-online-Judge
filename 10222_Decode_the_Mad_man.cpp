#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

char mp[]={"[czaqsdfyghjbvui w]etx  r;"};

int main()
{
    char str[1000];
    int i;
    while(gets(str))
    {
        for(i=0;str[i];i++)
        {
            if(isalpha(str[i]) && str[i]!='Q' && str[i]!='q' && str[i]!='w' && str[i]!='W' && str[i]!='X' && str[i]!='x')
            {
                if(isupper(str[i]))
                printf("%c",mp[str[i]-'A']);
                else if(islower(str[i]))
                printf("%c",mp[str[i]-'a']);
            }
            else if(str[i]=='x' || str[i]=='X')
            printf("%c",39);
            else if(str[i]==39)
            printf("l");
            else if(str[i]=='[')
            printf("o");
            else if(str[i]==']')
            printf("p");
            else if(str[i]==';')
            printf("k");
            else if(str[i]=='/')
            printf(",");
            else if(str[i]=='.')
            printf("m");
            else if(str[i]==',')
            printf("n");
            else
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
