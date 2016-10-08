#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    string str,str1;
    int x,h=0,l=0,high[100],low[100],i;
    bool dishonest=false;
    while(1)
    {
        scanf("%d",&x);
        if(x==0)
            break;
        cin>>str1>>str;

        if(str == "high")
           high[h++]=x;
        else if(str == "low")
            low[l++]=x;
        else
        {
            for(i=0;i<h;i++)
                if(x>=high[i])
                {
                    dishonest=true;
                    break;
                }
            if(!dishonest)
                for(i=0;i<l;i++)
                if(x<=low[i])
                {
                    dishonest=true;
                    break;
                }
            if(dishonest)
                printf("Stan is dishonest\n");
            else
                printf("Stan may be honest\n");
            h=l=0;
            dishonest=false;
        }
    }
    return 0;
}
