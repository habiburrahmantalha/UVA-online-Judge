#include<stdio.h>
#include<algorithm>

using namespace std;

int XLL1,XLR1,YLL1,YLR1,XLL2,XLR2,YLL2,YLR2;
int XUL1,XUR1,YUL1,YUR1,XUL2,XUR2,YUL2,YUR2;


bool no_overlap()
{
    if(YLL1>=YUR2 || YLL2>=YUR1)
        return true;
    if(YLL2>=YUR1 || YLL1>=YUR2)
        return true;
    if(XLL1>=XUR2 || XLL2>=XUR1)
        return true;
    if(XLL2>=XUR1 || XLL1>=XUR2)
        return true;
    return false;
}

int main()
{

    int tc,x[4],y[4];
    bool f=false;
    scanf("%d",&tc);

    while(tc--)
    {
        if(f)
            printf("\n");
        scanf("%d %d %d %d",&XLL1,&YLL1,&XUR1,&YUR1);
        scanf("%d %d %d %d",&XLL2,&YLL2,&XUR2,&YUR2);

        if(no_overlap())
            printf("No Overlap\n");
        else
        {
            x[0]=XLL1;
            x[1]=XUR1;
            x[2]=XLL2;
            x[3]=XUR2;

            y[0]=YLL1;
            y[1]=YUR1;
            y[2]=YLL2;
            y[3]=YUR2;

            sort(x,x+4);
            sort(y,y+4);
            printf("%d %d %d %d\n",x[1],y[1],x[2],y[2]);
            f=true;
        }
    }
    return 0;
}
