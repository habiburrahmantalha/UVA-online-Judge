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


int T1[30],T2[30];
bool isEncrypt()
{
    for(int i=0;i<30;i++)
        if(T1[i]!=T2[i])
            return false;
    return true;
}
int main()
{
    char A[1010],B[1010];
    int i;

    while(gets(A))
    {
        gets(B);
        memset(T1,0,sizeof(T1));
        memset(T2,0,sizeof(T2));
        for(i=0;A[i];i++)
        {
            if(isupper(A[i]))
            {
                T1[A[i]-'A']++;

            }
        }
        sort(T1,T1+30);
        for(i=0;B[i];i++)
        {
            if(isupper(B[i]))
            {
                T2[B[i]-'A']++;
            }
        }
        sort(T2,T2+30);
        if(isEncrypt())
            printf("YES\n");
        else
            printf("NO\n");


    }
    return 0;
}
