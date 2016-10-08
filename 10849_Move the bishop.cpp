#include<stdio.h>
#include<stdlib.h>

#define LL long long
bool is_black(LL a,LL b)
{
    if((a&1) && (b&1))
    return true;
    if(!(a&1) && !(b&1))
    return true;

    return false;
}
bool is_diyagonal(LL a,LL b,LL c,LL d)
{
    if(abs(a-b)==abs(c-d))
    return true;
    return false;
}
int main()
{
    LL tc,q,n,x1,x2,y1,y2;
    bool s1,s2;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld",&q);
        scanf("%lld",&n);
        while(q--)
        {
            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
            s1=is_black(x1,y1);
            s2=is_black(x2,y2);
            if(x1==x2 && y1==y2)
            printf("0\n");
            else if((s1 && s2) || (!s1 && !s2) )
            {
                if(is_diyagonal(x1,x2,y1,y2))
                printf("1\n");
                else
                printf("2\n");
            }
            else
            printf("no move\n");
        }
    }
    return 0;
}
