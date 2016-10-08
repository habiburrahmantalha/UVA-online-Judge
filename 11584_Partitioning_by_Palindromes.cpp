#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

vector<int>is_new[150];
char line[1010];
int res[1010];

bool is_palindrom(int i,int j)
{
    //printf("->%d %d\n",i,j);
    int m,n;
    for(m=i,n=j;m<=n;m++,n--)
    if(line[m]!=line[n])
    return false;

    //for(int k=i;k<=j;k++)
    //printf("%c",line[k]);
    //printf("\n");
    return true;
}
int palindrom(int k)
{
    int mn,i,j;

    mn=10000;
    for(i=0;i<is_new[line[k]].size();i++)
    {
        j=is_new[line[k]][i];
        if(is_palindrom(j,k))
        {
            if(j==0)
            return 1;
            else if(res[j-1]<mn)
            {
                mn=res[j];
            }
        }
    }
    if(mn==10000)
    return res[k-1]+1;
    else
    return mn+1;
}

int main()
{
    int tc,i;

    scanf("%d",&tc);

    while(tc--)
    {
        memset(res,0,sizeof(res));
        scanf("%s",&line);
        res[0]=1;
        is_new[line[0]].push_back(0);
        for(i=1;i<line[i];i++)
        {
            if(is_new[line[i]].size()==0)
            {
                res[i]=res[i-1]+1;
                is_new[line[i]].push_back(i);
            }
            else
            {

                res[i]=palindrom(i);
                is_new[line[i]].push_back(i);
            }

        }
        for(int j=0;j<i;j++)
        printf("%d ",res[j]);
        printf("%d\n",res[i-1]);

        for(i=90;i<=130;i++)
        is_new[i].clear();
    }
    return 0;
}
