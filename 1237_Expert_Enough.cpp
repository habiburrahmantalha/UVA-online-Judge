#include<stdio.h>
#include<algorithm>
using namespace std;

struct creator
{
    char name[25];
    int L,H;
};
bool comp(creator i,creator j)
{
    if(i.L==j.L)
    return i.H<j.H;
    return i.L<j.L;
}
int main()
{
    creator x[10010];
    int tc,i,j,res,n,q,y;
    bool f,NL=false;
    scanf("%d",&tc);
    while(tc--)
    {
        if(NL)
        printf("\n");
        NL=true;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s %d %d",x[i].name,&x[i].L,&x[i].H);
        //sort(x,x+n,comp);
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d",&y);
            f=false;
            for(j=0;j<n;j++)
            {
                if(y>=x[j].L && y<=x[j].H)
                {
                    if(f)
                    {
                        f=false;
                        break;
                    }
                    else
                    {
                        res=j;
                        f=true;
                    }
                }
            }
            if(f)
            printf("%s\n",x[res].name);
            else
            printf("UNDETERMINED\n");

        }
    }
    return 0;
}
