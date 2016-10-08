#include<stdio.h>
#include<string.h>
char c[5011],fib[5010][1010];

void bigadd(char a[],char b[],int index)
{
	int i,j,k,l1,l2,carry,sum;

	l1=strlen(a);
	l2=strlen(b);
	carry=0;
	sum=0;
	for(i=l1-1,j=l2-1,k=5010;i>=0 && j>=0 ;i--,j--,k--)
	{
		sum=a[i]+b[j]-2*'0'+carry;
		c[k]=sum%10+'0';
		carry=sum/10;
	}
	for(;i>=0;i--,k--)
	{
		sum=a[i]-'0'+carry;
		c[k]=sum%10+'0';
		carry=sum/10;
	}

	if(carry)
	{
		c[k--]='1';
	}
	strcpy(fib[index],&c[k+1]);

}

void fibonacci()
{
    fib[0][0]=0+'0';
    fib[1][0]=1+'0';
    fib[2][0]=1+'0';
    for(int i=3;i<5000;i++)
    bigadd(fib[i-1],fib[i-2],i);
}
int main()
{
    fibonacci();
	int x;
	while(scanf("%d",&x)==1)
	{

        printf("%s\n",fib[x]);
        //printf("%d\n",strlen(fib[x]));
	}
	return 0;
}
