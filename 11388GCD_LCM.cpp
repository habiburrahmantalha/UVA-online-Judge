//:P

#include<stdio.h>
int GCD(int a,int b)
{
    if(b==0)
    return a;
    else
    return GCD(b,a%b);
}

int main()
{
    int G,N,i,j,k;
    //scanf("%d",&N);
    //for(k=1;k<501;k++)
    while(scanf("%d",&N) && N)
    {
        //N=k;
        G=0;

        for(i=1;i<N;i++)

        for(j=i+1;j<=N;j++)
        {
            G+=GCD(i,j);

        }
        printf("%d\n",G);
    }
    return 0;

}
