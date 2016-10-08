#include<stdio.h>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

string to_str(int x)
{
    string str="";
    while(x)
    {
        str+=((x%10)+'0');
        x/=10;
    }
    reverse(str.begin(),str.end());
    return str;
}

bool is_palindrom(string str)
{
    int i,j;
    for(i=0,j=str.size()-1;i<=j;i++,j--)
    if(str[i]!=str[j])
    return false;

    return true;
}
void next_time(int a,int c)
{
    string str;
    int b;

    for(;a<24;a++)
    {
        for(b=c;b<60;b++)
        {

            str="";
            str+=to_str(a);
            if(a && b<10)
            str+="0";

            str+=to_str(b);

            if(is_palindrom(str))
            {
                if(a==0)
                printf("00:");
                else if(a<10)
                printf("0%d:",a);
                else
                printf("%d:",a);

                if(b==0)
                printf("00\n");
                else if(b<10)
                printf("0%d\n",b);
                else
                printf("%d\n",b);

                return;
            }
        }
        c=0;
    }
    printf("00:00\n");
}
int main()
{
    int tc,a,b;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d:%d",&a,&b);
        next_time(a,b+1);
    }
    return 0;
}
