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
    int tc,t=1,c,x,y,z,i;
    string a,b;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>a>>b;
        c=x=y=z=0;
        for(i=0;i<a.size();i++)
        {
            if(a[i]=='?')
            {
                c++;
                if(b[i]=='1')
                z++;
            }
            else if(a[i]!=b[i])
            {
                if(a[i]=='1' && b[i]=='0')
                x++;
                else
                y++;
            }

        }
        if(x==y)
        c+=x;
        else if(x<y)
        c+=y;
        else
        {
            if(x<=y+z)
                c+=x;
            else
                c=-1;
        }


        printf("Case %d: %d\n",t++,c);
    }
    return 0;
}
