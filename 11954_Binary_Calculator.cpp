#include<stdio.h>
#include<string.h>
#include<stack>
#include<string>
#include<bitset>
#include<stdlib.h>
using namespace std;

int main()
{
    int tc;
    stack<string> optr;
    string str;
    stack<int> opnd;
    bitset<1010> b;
    char x[100],ch;
    long long  y;
    bool f;
    scanf("%d",&tc);
    while(tc--)
    {
        f=false;
        int i;
        while(1)
        {
            while(scanf("%[a-z]",x))
            optr.push(x);
            while(scanf("%[ ]",x))
            i++;
            while(scanf("%[01]",x))
            {
                y=strtol (x,NULL,2);
                opnd.push(y);

            }
            while(scanf("%[ \n]",x))
            i++;
            for(i=0;x[i]!=0;i++)
            if(x[i]==10)
            {
                f=true;
                break;
            }
            if(f)
            break;


        }
        while(!optr.empty())
        {
            str=optr.top();
            optr.pop();
            if()
        }


    }
}

