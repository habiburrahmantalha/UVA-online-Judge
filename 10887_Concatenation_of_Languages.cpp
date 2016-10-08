//Problem Type : adhoc//hash compare
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
long long hash(char *str)
    {
	long long hash = 5381;
	int c;

	while (c = *str++)
	    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
    }

int main()
{
    int tc,a,b,t=1,i,j;
    char A[1510][15],B[1510][15],S[30];

    set<long long>s[25];

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&a,&b);
        gets(A[0]);
        for(i=0;i<a;i++)
        gets(A[i]);
        for(i=0;i<b;i++)
        gets(B[i]);
        for(i=0;i<b;i++)
        {
            for(j=0;j<a;j++)
            {
                S[0]=0;
                strcpy(S,A[j]);
                strcat(S,B[i]);
                //cout<<S<<" "<<hash(S)<<endl;
                s[strlen(S)].insert(hash(S));
            }
        }
        int c=0;
        for(i=0;i<25;i++)
        c+=s[i].size();
        printf("Case %d: %d\n",t++,c);
        for(i=0;i<25;i++)
        s[i].clear();
    }
    return 0;
}
