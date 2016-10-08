#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
    int tc,n,i,j;
    bool f;
    string x,y;
    scanf("%d",&tc);
    while(tc--)
    {
        cin >> x;
        scanf("%d",&n);
        while(n--)
        {
            cin >> y;
            f=false;
            for(i=0;i<x.size()-y.size()+1;i++)
            {
                for(j=0;j<y.size();j++)
                {
                    if(x[i+j]!=y[j])
                        break;
                }
                if(j==y.size())
                {
                    f=true;
                    break;
                }
            }
            if(f)
            printf("y\n");
            else
            printf("n\n");
        }
    }
    return 0;
}
