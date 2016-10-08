#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;
double digit[10000010];

void factorial_digit()
{
    int i;
    for(i=1;i<10000010;i++)
    {
        digit[i]=log10(i);
        digit[i]+=digit[i-1];
        digit[i-1]=floor(digit[i-1])+1;
    }

}
int main()
{
    factorial_digit();
/*
    int tc;
    int n;


    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);
        printf("%.0lf\n",digit[n]);
    }
    */
    return 0;
}
