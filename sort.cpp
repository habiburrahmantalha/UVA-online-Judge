#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct a
{
    char name[20];
    int time;
};

bool comp(a i,a j)
{
    if(i.time==j.time)
        return strcmp(i.name , j.name);
    return (i.time < j.time);
}


int main()
{
    a b[10];
    for(int i=0;i<10;i++)
    {
        scanf("%s %d",b[i].name,&b[i].time);
    }
    sort(b,b+10,comp);

    for(int i=0;i<10;i++)
        printf("%s %d\n",b[i].name,b[i].time);
    return 0;
}
