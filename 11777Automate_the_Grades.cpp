#include<stdio.h>
#include<algorithm>

using namespace std;

char grade(int x)
{
    if(x>=90)
    printf("A\n");
    else if(x>=80 && x<90)
    printf("B\n");
    else if(x>=70 && x<80)
    printf("C\n");
    else if(x>=60 && x<70)
    printf("D\n");
    else if(x<60)
    printf("F\n");
}
int main()
{
    int T1,T2,F,A,C[3],marks,tc,i;
    scanf("%d",&tc);
    for(i=1;i<=tc;i++)
    {
        scanf("%d %d %d %d %d %d %d",&T1,&T2,&F,&A,&C[0],&C[1],&C[2]);
        sort(C,C+3);
        marks=T1+T2+F+A+(C[1]+C[2])/2;

        printf("Case %d: ",i);
        grade(marks);
    }
    return 0;
}
