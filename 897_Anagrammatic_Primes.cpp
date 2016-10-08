#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 1010
#include<algorithm>
using namespace std;


bool mark[N+5];
int AP[N+5];
void sieve ()
{
    long long i,j;
    memset (mark, true, sizeof (mark));
    mark [0] = mark [1] = false;

    for (i = 4; i <=N; i += 2 )
        mark [i] = false;

    for (i = 3; i * i <= N; i++ )
    {
        if ( mark [i] )
        {
            for (j = i * i; j < N; j += 2 * i )
                mark [j] = false;
        }
    }

}

int to_int(int in,int a[])
{
    int i,num=0;
    for(i=0;i<in;i++)
        num+=a[i]*pow(10,i);
    return num;
}
void Anagrammatic_Primes()
{
    int in,a[20],f,i,x,c=0;
    memset(AP,1,sizeof(AP));

    for(i=1;i<=N;i++)
    {
        if(mark[i])
        {
            x=i;
            in=0;
            f=0;
            while(x)
            {
                a[in]=x%10;
                if(a[in]%2==0 || a[in]==5)
                {
                    f=1;
                    AP[i]=0;
                    break;
                }
                x/=10;
                in++;
            }
            if(f==0)
            {
                sort(a,a+in);
                do
                {
                    if(!mark[to_int(in,a)])
                    {
                       AP[i]=0;
                       break;
                    }
                }while(next_permutation(a,a+in));
            }

        }
        else
            AP[i]=0;
    }
    AP[2]=AP[5]=1;
    /*
    for(i=1;i<1001;i++)
        if(AP[i])
        {
            printf("%d ",i);
            c++;
        }
    printf("%d\n",c);
    */
}
int main()
{
    sieve();
    Anagrammatic_Primes();
    int n,i,m,f;
    while(scanf("%d",&n) && n)
    {
        if(n<0)
            n=0;
        if(n<=1000)
        {
            m=1;
            f=0;
            while(m<=n)
                m*=10;
            for(i=n+1;i<m;i++)
                if(AP[i])
                {
                    printf("%d\n",i);
                    f=1;
                    break;
                }
            if(f==0)
                printf("0\n");
        }
        else
            printf("0\n");
    }
    return 0;
}
