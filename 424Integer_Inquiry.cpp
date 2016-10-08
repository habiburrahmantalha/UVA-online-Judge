//আবার করতে হবে B(
#include<stdio.h>
#include<string.h>
char c[100004],result[100007];
void bigadd(char a[],char b[])
{
	int i,j,k,l1,l2,carry,sum;
	l1=strlen(a);
	l2=strlen(b);
	carry=0;
	sum=0;
	for(i=l1-1,j=l2-1,k=100000;i>=0 && j>=0 ;i--,j--,k--)
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
	for(;j>=0;j--,k--)
	{
		sum=b[j]-'0'+carry;
		c[k]=sum%10+'0';
		carry=sum/10;
	}
	if(carry)
	{
		c[k--]='1';
	}
	strcpy(result,&c[k+1]);
}
int main()
{
	char s[100000],res[100000];
	strcpy(res,"0");
	while(scanf("%s",s)==1)
	{
		if(strcmp(s,"0")==0)break;
		bigadd(s,res);
		strcpy(res,result);
	}
	printf("%s\n",res);
	return 0;
}
