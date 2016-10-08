#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;

bool comp(char a,char b)
{
    return (a>b);
}

int main()
{
    char a[15];
    int i;
    double small,large;
    while ( scanf ("%s", a) != EOF )
    {
        sort(a,a+strlen(a),comp);
        large=atof(a);
        sort(a,a+strlen(a));
        //printf("%s",a);

        if(a[0]=='0')
        {
            for(i=1;a[i]!=0;i++)
            if(a[i]!='0')
            {
                a[0]^=a[i];
                a[i]^=a[0];
                a[0]^=a[i];
                break;
            }
        }
        small=atof(a);
        printf ("%0.lf - %0.lf = %0.lf = 9 * %0.lf\n",large, small, large - small, (large - small)/9);
    }
    return 0;
}
