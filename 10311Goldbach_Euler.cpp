#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define N 100000001
//bool *prime=(bool*)malloc(N*1);

//bool *prime=(bool*)calloc(N, 1);
bool prime[N];
void sieve()
{
    int i,j,k;
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    k=0;
    for(i=2;i*i<=100000000;i++)
    {
        if(prime[i])
        {
            for(j=i+i;j<=100000000;j+=i)
            prime[j]=false;

        }
    }
}

/*
void sieve()
{

/*
	int i,j;
	for(i=2;i<N;i++)
		    prime[i]=1;

	for ( i = 2;i <10001; i ++ )
	{
		if ( prime[i] )
		{
			for ( j = i + i; j <N; j += i )
				prime[j] = 0;
		}


	}

	///*
    //memset (prime, true, sizeof (prime));
    //for(int i=2;i<N;i++)
		    //prime[i]=true;



    prime [0] = prime [1] = 1;

    for ( int i = 4; i < N; i += 2 )
        prime [i] = 1;

    for ( int i = 3; i*i <N; i++ )
    {
        if ( prime [i] ==0)
        {
            for ( int j = i * i; j < N; j += 2 * i )
                prime [j] = 1;
        }
    }

    //for ( int i = 2; i < 100; i ++ )
    //if(prime[i])
    //printf("%d\n",i);
    //prime[1]=1;
    int i,count =0;
    for(i=1;i<N;i++)
    {
        if(prime[i]==0)
        {
            count++;
            //for(j=N-1;j>=0;j--)
            {

            }
        }
    }
printf("%d",count);

}

*/
int main()
{

	sieve();

	int x,y,i,z;
	bool f;
	/*
    while(scanf("%d",&x)==1)
    {
        f=false;

        y=x/2;
        for(i=2;i<y;i++)
        {
            if(prime[i] && prime[x-i])
            {
                z=i;
                f=true;
            }

        }
        if(f==false)
        printf("%d is not the sum of two primes!\n",x);
        else
        printf("%d is the sum of %d and %d.\n",x,z,x-z);
    }
*/
    return 0;
}
