#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<map>
using namespace std;

char N[12],M[12];

void chain_sort()
{
    sort(N,N+strlen(N));
    strcpy(M,N);
    reverse(M,M+strlen(M));
}
void chain()
{
    int m,n,count=0,o,in;
    map<int,int> mp;
    bool f=false;
    while(1)
    {

        chain_sort();

        n=atoi(N);
        m=atoi(M);
        o=m-n;

        if(mp[o]==1)
        {
            printf("%d - %d = %d\n",m,n,o);
            count++;
            printf("Chain length %d\n",count);
            return;
        }
        else
        {
            printf("%d - %d = %d\n",m,n,o);
            count++;
            mp[o]=1;

            in=0;
            while(o)
            {
                N[in++]=o%10+'0';
                o/=10;
            }
            N[in]=0;
        }
    }
}
int main()
{
    while(1)
    {
        scanf("%s",N);
        if(strcmp(N,"0")==0)
            break;
        printf("Original number was %s\n",N);
        chain();
        printf("\n");
    }
    return 0;
}
