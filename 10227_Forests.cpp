#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    set<int>p[101];

    int tc,n,t,y,a,b,i,j;
    string str;
    bool f[101],nline=false;
    char ch;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        if(nline)
            printf("\n");
        memset(f,true,sizeof(f));
        scanf("%d %d",&n,&t);
        getchar();
        while(1)
        {
            getline(cin,str);
            if(str.size()==0)
                break;
            stringstream ss(str);
            ss>>a>>b;
            p[a].insert(b);
        }

        int count=0,c=0;
        for(i=1;i<=n;i++)
        if(p[i].empty())
        {
            f[i]=false;
            c++;
        }
        for(i=1;i<=n;i++)
        {
            if(f[i])
            for(j=i+1;j<=n;j++)
            {
                if(p[i]==p[j])
                {
                    f[j]=false;
                    count++;
                }
            }
        }
        if(c>0)
            c-=1;
        printf("%d\n",n-count*2-c+count);
        nline=true;
        for(i=0;i<=n;i++)
        p[i].clear();
    }
    return 0;
}
