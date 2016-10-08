#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)


int main()
{
    char a[20];
    int n;
    scanf("%d",&n);
    while(n--)
    {

        scanf("%s",a);

        int x = abs(((a[0]-'A')*26*26+(a[1]-'A')*26+a[2]-'A')-((a[4]-'0')*1000+(a[5]-'0')*100+(a[6]-'0')*10+a[7]-'0'));
        //cout<<x<<endl;
        if(x<=100)
            printf("nice\n");
        else
            printf("not nice\n");
    }
    return 0;
}
