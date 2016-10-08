//lot's of work
#include<stdio.h>
#include<string>
#include<string.h>
#include<string.h>
#include<iostream>

using namespace std;

int tc=1,m,n;
char words[15][15];
void print()
{
    string temp="";
    int i,j,x=0;
    printf("puzzle #%d\n",tc++);
    printf("Across\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(words[i][j]!='*')
            temp+=words[i][j];
            else
            {
                if(temp.size()>0)
                {
                    x=i*m+j+1-temp.size();
                    printf("%3d.",x);
                    cout<<temp<<endl;
                    temp="";
                }
            }
        }
    }
}
int main()
{
    int i;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&m);

        for(i=0;i<n;i++)
        {
            scanf("%s",words[i]);
            words[i][m]='*';
        }

        print();
    }
    return 0;
}
