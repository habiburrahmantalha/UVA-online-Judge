#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    char str[1000000];
    int i,len;
    double x;
    while(scanf("%s",str) && str[0]!='0')
    {
        len=strlen(str);
        if(len&1)
        {
            x=floor(sqrt(str[0]-'0'));
            printf("%.0lf",x);
            for(i=0;i<(len-1)/2;i++)
                printf("0");
            printf("\n");
        }
        else
        {
            x=floor(sqrt(str[1]-'0'+10*(str[0]-'0')));
            printf("%.0lf",x);
            for(i=0;i<(len-2)/2;i++)
                printf("0");
            printf("\n");
        }
    }
    return 0;
}
