// x(((((((((((((((
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<string>
#include<iostream>
#include<map>
using namespace std;

int main()
{
    map <char, int> press;
    press[' '] = press['a'] = press['d'] = press['g'] = press['j'] = press['m'] = press['p'] = press['t'] = press['w'] = 1;
    press['b'] = press['e'] = press['h'] = press['k'] = press['n'] = press['q'] = press['u'] = press['x'] = 2;
    press['c'] = press['f'] = press['i'] = press['l'] = press['o'] = press['r'] = press['v'] = press['y'] = 3;
    press['s'] = press['z'] = 4;


    int tc,count,k,i;
    string line;

    scanf("%d",&tc);
    getline(cin,line);
    for(k=1;k<=tc;k++)
    {
        count=0;
        getline(cin,line);

        for(i=0;i<line.size();i++)
        {
            count+=press[line[i]];
        }
        printf("Case #%d: %d\n",k,count);
    }
    return 0;
}
