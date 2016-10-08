#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct fr
{
    int asci;
    int frequency;
};

bool comp(fr a, fr b)
{
    if(a.frequency==b.frequency)
        return a.asci>b.asci;
    return a.frequency<b.frequency;
}
int main()
{
    char line[1010];
    fr x[130];
    int i,len;
    bool f=false;

    while(gets(line))
    {
        if(f)
            printf("\n");

        for(i=0;i<130;i++)
            x[i].frequency=0;


        len=strlen(line);
        for(i=0;i<len;i++)
        {

            if(line[i]>=32 && line[i]<128)
            {
                x[line[i]].asci=line[i];
                x[line[i]].frequency++;
            }
        }
        sort(x,x+128,comp);

        for(i=0;i<128;i++)
        {
            if(x[i].frequency)
                printf("%d %d\n",x[i].asci,x[i].frequency);
        }
        f=true;
    }
    return 0;
}
