//Problem Type :
//Time :
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
    int tc,c,b,n,c1,c2,c3;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d %d",&n,&c1,&c2,&c3);

            c=0;
            b=0;

            while(b<n && c3)
            {
                c3--;
                c1+=2;
                c++;
                b++;
            }
            cout<<c1<<" "<<c2<<" "<<c3<<" "<<c<<" "<<b<<" "<<endl;
            while(b<n && c2>1)
            {
                c2-=2;
                c1+=2;
                c+=2;
                b++;
            }
            cout<<c1<<" "<<c2<<" "<<c3<<" "<<c<<" "<<b<<" "<<endl;
            if(b<n && c2)
            {
                c2--;
                c1-=3;
                c+=4;
                b++;
            }
            cout<<c1<<" "<<c2<<" "<<c3<<" "<<c<<" "<<b<<" "<<endl;

            if(b<n)
            {
                int x=(n-b);
                c+=x*8;

            }

            cout<<c1<<" "<<c2<<" "<<c3<<" "<<c<<" "<<b<<" "<<endl;
            printf("%d\n",c);

    }
    return 0;
}
