//unfinished
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct l_f
{
    char l;
    int f;
};

bool comp(l_f i,l_f j)
{
    return i.f>j.f;
}

int main()
{
    l_f a[130],b[130];
    int tc,i,m,n,in1,in2;
    char key[1000],encode[1000];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",key);
        scanf("%s",encode);

        for(i=0;key[i]!=0;i++)
        {

            a[key[i]].l=key[i];
            if(a[key[i]].f>0)
            n++;
            a[key[i]].f++;
            b[encode[i]].l=encode[i];
            if(b[encode[i]].f>0)
            m++;
            b[encode[i]].f++;

        }
        l_f c[n],d[m];
        m=n=in1=in2=0;
        for(i=0;i<30;i++)
        {
            if(a[i].f>0)
            {
                c[in1].l=a[i].l;
                c[in1++].f=a[i].f;
            }
            if(b[i].f>0)
            {
                d[in2].l=b[i].l;
                c[in2++].f=b[i].f;
            }
        }

        sort(c,c+n,comp);
        sort(d,d+m,comp);

        for(i=0;i<n;i++)
        printf("%c %d\n",c[i].l,c[i].f);
    }
}
