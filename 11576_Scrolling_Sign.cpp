#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
string str;
char x[110];
bool match(int i,int j)
{
    for(;i<str.size();i++,j++)
    if(str[i]!=x[j])
    return false;

    return true;
}
int main()
{
    int tc,i,j,k,w;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&k,&w);
        scanf("%s",x);
        str=x;
        w--;
        while(w--)
        {
            scanf("%s",x);
            i=str.size()-k;
            j=k;
            while(!match(i,0))
            {
                i++;
                j--;
            }
            //for(;i<str.size();i++)
            //printf("%c",str[i]);
            //printf("\n");
            for(i=j;i<k;i++)
            str+=x[i];
        }
        printf("%d\n",str.size());
    }
    return 0;
}
