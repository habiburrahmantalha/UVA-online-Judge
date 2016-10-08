#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int main()
{
    int x,y,i;
    double X[1010],Y[1010],w;
    bool f;

    while(scanf("%d %d %lf",&x,&y,&w))
    {
        if(x==0 && y==0 && w==0)
            break;
        w/=2;
        for(i=0;i<x;i++)
            scanf("%lf",&X[i]);

        for(i=0;i<y;i++)
            scanf("%lf",&Y[i]);

        sort(X,X+x);
        sort(Y,Y+y);
        f=true;

        if(w<X[0]-w)
            f=false;
        if(f)
        for(i=0;i<x-1;i++)
        if(X[i]+w<X[i+1]-w)
        {
            f=false;
            break;
        }
        if(X[i]+w<75)
            f=false;
        if(w<Y[0]-w)
            f=false;
        if(f)
        for(i=0;i<y-1;i++)
        if(Y[i]+w<Y[i+1]-w)
        {
            f=false;
            break;
        }
        if(Y[i]+w<100)
            f=false;
        if(f)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
