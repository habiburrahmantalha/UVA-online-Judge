#include<stdio.h>
#include<string.h>

#define N 10001

int a[N]={0};
void divisor()
{
    int i,j;
    for ( i = 1; i <N; i++ )
	{
		for ( j = i; j <N; j+=i )
			a[j]+=1;
	}
}

bool mark [N+10];

void sieve ()
{
    int i,j;
    memset (mark, true, sizeof (mark));
    mark [0] = mark [1] = false;

    for (i = 4; i < N; i += 2 )
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
int main()
{
    sieve();
    divisor();

    int tc,i,L,H;
    bool f;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d %d",&L,&H);
        f=false;
        for(i=L;i<=H;i++)
        {
            if(mark[a[i]])
            {
                printf("%d",i);
                f=true;
                break;
            }
        }
        if(f)
        {
            for(i=i+1;i<=H;i++)

            if(mark[a[i]])
                printf(" %d",i);
            printf("\n");
        }
        else
            printf("-1\n");


    }

    return 0;
}
