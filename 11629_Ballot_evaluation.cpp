//Problem Type : map
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
#define eps 1e-9
map<string,int> mp;

int isoperator(string s)
{
    if(s=="<")
    return 1;
    else if(s==">")
    return 2;
    else if(s=="<=")
    return 3;
    else if(s==">=")
    return 4;
    else if(s=="=")
    return 5;
    else
    return 0;
}
int main()
{

    int n,g,c,x,y,z,i,t=1;
    string a,d;
    bool guess;
    double b;
    while(scanf("%d %d",&n,&g)==2)
    {
        for(i=0;i<n;i++)
        {
            cin>>a>>b;
            b+=eps;
            b*=10;
            c=b;
            mp[a]=c;
        }
        for(i=0;i<g;i++)
        {
            y=0;
            while(cin>>a>>d)
            {
                y+=mp[a];
                x=isoperator(d);
                if(x)
                break;
            }
            cin>>z;
            z*=10;
            guess=false;
            switch(x)
            {
                case 1 :
                {
                    //cout<<x<<y<<" "<<z<<endl;
                    if(y<z)
                    guess=true;
                    break;
                }
                case 2 :
                {
                    //cout<<x<<y<<" "<<z<<endl;
                    if(y>z)
                    guess=true;
                    break;

                }
                case 3 :
                {
                    //cout<<x<<y<<" "<<z<<endl;
                    if(y<=z)
                    guess=true;
                    break;

                }
                case 4 :
                {
                    //cout<<x<<y<<" "<<z<<endl;
                    if(y>=z)
                    guess=true;
                    break;

                }
                case 5 :
                {
                    //cout<<x<<y<<" "<<z<<endl;
                    if(y==z)
                    guess=true;
                    break;

                }
            }
            if(guess)
            printf("Guess #%d was correct.\n",t++);
            else
            printf("Guess #%d was incorrect.\n",t++);

        }
        mp.clear();
    }
    return 0;
}
