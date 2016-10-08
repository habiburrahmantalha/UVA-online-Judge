#include<stdio.h>

int C[201];

void cube()
{
    for(int i=2;i<=200;i++)
        C[i]=i*i*i;
}

int main()
{
    cube();
    int i,j,k,n;
    for(n=6;n<=200;n++)
    {
        for(i=2;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    if(C[n]==C[i]+C[j]+C[k])
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",n,i,j,k);
                }
            }
        }
    }
    return 0;
}
