#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;


int main()
{
    int tc,i,j,k,c,x,n,d;
    bool f;
    vector<int>red,blue;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x<0)
            red.push_back(-x);
            else
            blue.push_back(x);
        }
        sort(red.begin(),red.end());
        sort(blue.begin(),blue.end());
        c=d=0;
        if(red[0]<blue[0])
        {
            x=-1;
            k=0;
            c=0;
            f=true;
            for(i=0;i<red.size();i++)
            {
                if(red[i]>x && f)
                {
                    x=red[i];
                    f=false;
                    c++;
                    for(j=k;j<blue.size();j++)
                    {
                        if(blue[j]>x)
                        {
                            k=j;
                            x=blue[j];
                            c++;
                            f=true;
                            break;
                        }
                    }
                }
            }
        }
        else

        {
            x=-1;
            k=0;
            d=0;
            f=true;
            for(i=0;i<blue.size();i++)
            {
                if(blue[i]>x && f)
                {
                    x=blue[i];
                    f=false;
                    d++;
                    for(j=k;j<red.size();j++)
                    {
                        if(red[j]>x)
                        {
                            k=j;
                            x=red[j];
                            d++;
                            f=true;
                            break;
                        }
                    }
                }
            }
        }

        if(d>c)
        c=d;
        printf("%d\n",c);
        red.clear();
        blue.clear();
    }
    return 0;
}
