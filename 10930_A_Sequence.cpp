#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    bool f[1010],A_seq;
    int t=1,n,A[35],i,j,S[1010];
    while(scanf("%d",&n)==1)
    {
        A_seq=true;
        memset(f,false,sizeof(f));
        for(i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
            f[A[i]]=true;
        }
        printf("Case #%d: ",t++);
        for(i=0;i<n-1;i++)
            printf("%d ",A[i]);
        printf("%d\n",A[i]);


        if(A[0]<1)
            A_seq=false;

        if(A_seq)
        for(i=0;i<n-1;i++)
            if(A[i]>=A[i+1])
            {
                A_seq=false;
                break;
            }

        if(A_seq)
        {
            memset(S,0,sizeof(S));
            S[0]=1;

            for(i=0;i<n;i++)
            {
                for(j=1000-A[i];j>=0;j--)
                    if(S[j])
                        S[j+A[i]]++;
            }

            for(i=0;i<=1000;i++)
            if(S[i]>1 && f[i])
            {
                A_seq=false;
                break;
            }
        }

        if(A_seq)
            printf("This is an A-sequence.\n");
        else
            printf("This is not an A-sequence.\n");
    }
    return 0;
}
