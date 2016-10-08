#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)

class Matrix
{
    public : int m[3][3];

    public : void print()
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            cout<<m[i][j]<<" ";
            cout<<endl;
        }
    }

    public : Matrix multiply(Matrix a)
    {

        Matrix b;
        memset(b.m,0,sizeof(b.m));
        for(int k=0;k<3;k++)
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                b.m[i][j]+=a.m[i][k]*m[k][j];
            }
        }
        return b;
    }
};


int main()
{
    Matrix M[60];
    memset(M[0].m,0,sizeof(M[0].m));
    M[0].m[0][0]=M[0].m[0][1]=M[0].m[0][1]=M[0].m[1][0]=M[0].m[2][1]=1;

    for(int i=1;i<60;i++)
    M[i] = M[i-1].multiply(M[i-1]);

    M[10].print();
    return 0;
}
