#include<stdio.h>
#include<math.h>

int main()
{
    int tc,m,n,res;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&m,&n);
        res=floor(m/3)*floor(n/3);
        printf("%d\n",res);
    }
    return 0;

}
