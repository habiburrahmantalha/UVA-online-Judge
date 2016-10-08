#include<stdio.h>
#include<string.h>

int divisor[1000010]={0};

void caldiv()
{
    int i,j;
    for ( i = 1; i <= 1000000; i++ )
	{
		for ( j = i; j <= 1000002; j+=i )
			divisor[j]+=1;
	}
}



int main()
{
    caldiv();
    //freopen("INPUT.txt","r",stdin);
    //freopen("OUTPUT.txt","w",stdout);

    int i,nod[1000001],N[1000001];

    memset(N,0,sizeof(N));

    nod[0]=1;
    nod[1]=2;
    N[0]=1;
    N[1]=1;
    for(i=1;i<80000;i++)
    {
        if(nod[i]>1000000)
        break;
        nod[i]=nod[i-1]+divisor[(nod[i-1])];
        N[nod[i]]=N[nod[i-1]]+1;
    }

    int t,a,b,count,j,k;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        scanf("%d %d",&a,&b);

        while(1)
        if(!N[a])
        a++;
        else
        break;


        while(1)
        if(!N[b])
        b--;
        else
            break;

        printf("Case %d: %d\n",j+1,N[b]-N[a]+1);

    }

    return 0;
}



