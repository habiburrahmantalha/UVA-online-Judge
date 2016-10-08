#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define RANGE 1000000


bool *prime=(bool*)calloc(RANGE, 1);


int sieve()
{
	int i,j;
	for(i=2;i<=RANGE;i++)
		prime[i]=1;

	double lim=sqrt(RANGE);
	for ( i = 2;i <= lim; i ++ )
	{
		if ( prime[i] )
		{
			for ( j = i + i; j <= RANGE; j += i )
				prime[j] = 0;
		}
	}


}

int main(void)
{
    sieve();
    int i,j,len,t;
    int frd[10],fral[30],frau[30];
    char s[2010],printout[2010];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        memset(frd,0,sizeof(frd));
        memset(frau,0,sizeof(frau));
        memset(fral,0,sizeof(fral));
        scanf("%s",s);
        len=strlen(s);
        for(j=0;j<len;j++)
        {
            if(isdigit(s[j]))
            frd[s[j]-'0']++;
            else
            {
                if(isupper(s[j]))
                frau[s[j]-'A']++;
                else
                fral[s[j]-'a']++;
            }
        }
        int in=0;
        for(j=0;j<10;j++)
        if(frd[j] && prime[frd[j]])
        printout[in++]=j+'0';
        //printf("%c %d\n",j+'0',frd[j]);

        for(j=0;j<26;j++)
        if(frau[j] && prime[frau[j]])
        printout[in++]=j+'A';
        //printf("%c %d\n",j+'A',frau[j]);

        for(j=0;j<26;j++)
        if(fral[j] && prime[fral[j]])
        printout[in++]=j+'a';
        printout[in]='\0';
        //printf("%c %d\n",j+'a',fral[j]);
        len=strlen(printout);
        if(len==0)
        printf("Case %d: empty\n",i+1);
        else
        printf("Case %d: %s\n",i+1,printout);
    }


	free(prime);
	return 0;
}
