#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define n 100000

int prime[n+5];
void sieve()
{
	int i,j;
	for(i=1;i<=n;i++)
		prime[i]=1;
    int lim=sqrt(n);
	for ( i = 2;i <= lim; i ++ )
	{
		if ( prime[i] )
		{
			for ( j = i + i; j <= n; j += i )
				prime[j] = 0;
		}
	}
	//int count=0;
	//for(i=0;i<n;i++)
	//if(prime[i])
	//count++;
	//printf("%d",count);
}
int main()
{
    //freopen("in.txt","r",stdin);
    sieve();
    char x[100];
    int len,i,sum;
    while(scanf("%s",x)==1)
    {
        //gets(x);
        //if(strcmp(x,EOF)==0)
        //break;
        len=strlen(x);
        sum=0;
        for(i=0;i<len;i++)
        {
            if(islower(x[i]))
            //printf("%d ",x[i]-'a'+1);
            sum+=(x[i]-'a'+1);
            else if(isupper(x[i]))
            sum+=(x[i]-'A'+27);
            //printf("%d ",x[i]-'A'+27);
        }
        //printf("%d\n",sum);
        if(prime[sum])
        printf("It is a prime word.\n");
        else
        printf("It is not a prime word.\n");

    }
    return 0;
}
