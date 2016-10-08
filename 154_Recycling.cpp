//Problem Type :
//Time :    .008
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


int main()
{
    int i,j,k,l,c,mx,in;
    char a[110][6],b[110][6],s[110];
    map<char,char>color;

    while(gets(s))
    {
        if(s[0]=='#')
            break;
        i=0;
        do
        {
            sscanf(s,"%c/%c,%c/%c,%c/%c,%c/%c,%c/%c",&a[i][0],&b[i][0],&a[i][1],&b[i][1],&a[i][2],&b[i][2],&a[i][3],&b[i][3],&a[i][4],&b[i][4]);
            i++;
        }while(gets(s) && s[0]!='e');

        mx=0;
        in=0;
        for(j=0;j<i;j++)
        {
            c=0;
            for(l=0;l<5;l++)
            color[a[j][l]]=b[j][l];

            for(k=0;k<i;k++)
            {
                for(l=0;l<5;l++)
                    if(color[a[k][l]]==b[k][l])
                        c++;
            }
            if(c>mx)
            {
                mx=c;
                in=j+1;
            }
        }
        printf("%d\n",in);
    }
    return 0;
}
