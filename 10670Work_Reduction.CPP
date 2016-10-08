#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<math.h>
using namespace std;

struct work
{
    string name;
    int a,b,c;
};


bool comp(work i,work j)
{

    if(i.c==j.c)
    return (i.name<j.name);
    return (i.c<j.c);
}
int main()
{
    char ch;

    string a;
    int tc,i,k,N,M,L,x,y,z;
    scanf("%d",&tc);
    for(k=1;k<=tc;k++)
    {
        scanf("%d %d %d",&N,&M,&L);
        work paperwork[L+5];

        for(i=0;i<L;i++)
        {
            paperwork[i].name="";
            ch=getchar();
            while(ch!=':')
            {
                paperwork[i].name+=ch;
                ch=getchar();
            }
            scanf("%d,%d",&paperwork[i].a,&paperwork[i].b);
            paperwork[i].c=0;
        }

        for(i=0;i<L;i++)
        {
            x=N;
            y=M;
            while(x!=y)
            {
                z=ceil(x/2);
                if(z>=y)
                {
                    if(paperwork[i].b<=paperwork[i].a*z)
                    {
                        paperwork[i].c+=paperwork[i].b;
                        x=z;
                    }
                    else
                    {
                        paperwork[i].c+=((x-y)*paperwork[i].a);
                        x=y;
                    }
                }
                else
                {
                    paperwork[i].c+=((x-y)*paperwork[i].a);
                    x=y;
                }

            }

        }
        sort(paperwork,paperwork+L,comp);
        cout<<"Case "<<k;

        for(i=0;i<L;i++)
        cout<<paperwork[i].name<<" "<<paperwork[i].c;
        cout<<endl;
    }
    return 0;
}
