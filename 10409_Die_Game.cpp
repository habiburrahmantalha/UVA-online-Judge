//Problem Type : die
//Time :    .008
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

string str;

int get_dir()
{
    if(str=="north")
        return 1;
    if(str=="south")
        return 2;
    if(str=="west")
        return 3;
    else
        return 4;
}
int main()
{
    int n,top,down,south,north,west,east,temp;
    while(scanf("%d",&n) && n)
    {
        top=1;
        down=6;
        north=2;
        south=5;
        west=3;
        east=4;

        while(n--)
        {
            cin>>str;

            temp=get_dir();
            switch(temp)
            {
                case 1:
                {
                    temp=top;
                    top=south;
                    south=down;
                    down=north;
                    north=temp;
                    break;
                }
                case 2:
                {
                    temp=top;
                    top=north;
                    north=down;
                    down=south;
                    south=temp;

                    break;
                }
                case 3:
                {
                    temp=top;
                    top=east;
                    east=down;
                    down=west;
                    west=temp;
                    break;
                }
                case 4:
                {
                    temp=top;
                    top=west;
                    west=down;
                    down=east;
                    east=temp;

                    break;
                }
            }
        }
        printf("%d\n",top);
    }
    return 0;
}
