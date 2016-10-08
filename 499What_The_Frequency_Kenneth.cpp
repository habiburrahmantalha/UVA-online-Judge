#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct letter
{
    char l;
    int f;
};

letter a[27];
letter b[27];

void reset()
{
    char c;
    int i;

    for(i=0;i<27;i++)
    {
        a[i].f=0;
        b[i].f=0;
    }

    for(c='A';c<='Z';c++)
    a[c-65].l=c;
    for(c='a';c<='z';c++)
    b[c-97].l=c;
}

int main()
{
    string str;
    int max,i;
    while(getline(cin,str))
    {
        reset();
        max=0;

        for(i=0;i<str.size();i++)
        {
            if(isupper(str[i]))
            {
                a[str[i]-65].f++;
            }
            else if(islower(str[i]))
            {
                b[str[i]-97].f++;
            }
        }
        for(i=0;i<27;i++)
        {
            if(max<a[i].f)
            max=a[i].f;

            if(max<b[i].f)
            max=b[i].f;
        }
        for(i=0;i<27;i++)
        if(a[i].f==max)
        printf("%c",a[i].l);

        for(i=0;i<27;i++)
        if(b[i].f==max)
        printf("%c",b[i].l);

        printf(" %d\n",max);

    }
    return 0;
}
