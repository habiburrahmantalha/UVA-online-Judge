#include<stdio.h>
#include<math.h>
#include<vector>

using namespace std;
//vector<long long>C,D;
int C[1000010];
void cube()
{
    int i;
    C[0]=1;
    for(i=1;i*i*i<1000000;i++)
    {
        C[i*i*i]=i;
        //D[i*i*i]=i;
    }

}

int main()
{
    cube();
    bool f;
    int x;
    while(scanf("%d",&x) && x)
    {
        f=false;
        for(int i=0;i<1000000;i++)
        {

            if(C[i] && C[i+x])
            {
                if(i==0)
                printf("%d 0\n",C[i+x]);
                else
                printf("%d %d\n",C[i+x],C[i]);
                f=true;
                break;
            }
        }
        if(f==false)
        printf("No solution\n");
    }
    return 0;
}
