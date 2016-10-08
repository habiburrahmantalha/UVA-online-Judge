#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
#include <sstream>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,tc;
    string str,s;

    scanf("%d",&tc);

    getchar();
    getchar();
    for(i=1;i<=tc;i++)
    {
        if(i>1)
            printf("\n");
        printf("Case #%d:\n",i);

        while(1)
        {
            j=1;
            getline(cin,str);

            if(str.size()==0)
                break;

            stringstream ss(str);

            while(ss>>s)
            {
                if(s.size()>=j)
                {
                    printf("%c",s[j-1]);
                    j++;
                }
            }
            printf("\n");
            ss.clear();
        }

    }
    return 0;
}
