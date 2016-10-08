//Problem Type : bigint
//Time :
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

char res[100010];
void substruct(string a,string b)
{
    int i,j,c,x,y,r,k;

    k=max(a.size(),b.size())+10;
    res[k--]=0;
    c=0;
    for(i=a.size()-1,j=b.size()-1;i>=0 && j>=0;i--,j--)
    {
        x=a[i]-'0';
        y=b[j]-'0';
        x+=c;
        if(x<y)
        {
            r=10+x-y;
            c=1;
        }
        else
        {
            r=x-y;
            c=0;
        }
        res[k--]=r+'0';
    }
    strcpy(res,&res[k+1]);
    printf("%s\n",&res);

}

int main()
{
    int tc;
    string a,b;
    //scanf("%d",&tc);
    tc=5;
    while(tc--)
    {
        cin>>a>>b;
        substruct(a,b);

    }
    return 0;
}
