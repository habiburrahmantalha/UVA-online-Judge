#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int get_v(char ch)
{
    if(isdigit(ch))
        return ch-'0';
    else if(isupper(ch))
        return ch-'A'+10;
    else if(islower(ch))
        return ch-'a'+36;
}
int main()
{
    string str;

    int i,base,v,sum,j;
    bool found;
    while(getline(cin,str))
    {
        base=sum=0;
        found=false;
        for(i=0;i<str.size();i++)
        {
            v=get_v(str[i]);
            sum+=v;
            if(base<v)
            base=v;
        }
        if(base==0)
        printf("2\n");
        else
        {

            for(i=base+1;i<=62;i++)
            {

                if(sum%(i-1)==0)
                {
                    printf("%d\n",i);
                    found=true;
                    break;
                }

            }
            if(!found)
            printf("such number is impossible!\n");

        }
    }
    return 0;
}
