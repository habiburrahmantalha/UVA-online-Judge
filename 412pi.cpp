#include <cstdio>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
    return (!a ? b : gcd(b%a, a));
}

int main()
{
    int n,i,j;
    while (scanf("%d", &n)&&n)
    {
        int x[n], coprime = 0, total = 0;
        for(i=0;i<n;i++)
        scanf("%d",&x[i]);

        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                total++;
                if (gcd(x[i], x[j]) == 1)
                coprime++;
            }
        if (!coprime)
        printf("No estimate for this data set.\n");
        else
        printf("%.6f\n", sqrt(6.0*total/coprime));
    }
    return 0;
}
