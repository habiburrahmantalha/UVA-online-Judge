#include<string.h>
#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;
int B[100];
void bin()
{
    int i,j,x,s,y[100],in;
    for(i=65;i<100;i++)
    {
        x=i;
        in=0;
        while(x)
        {
            y[in++]=x%2;
            x/=2;
        }
        s=0;
        for(j=0;j<in;j++)
            if(y[j]==0)
            s+=250;
            else
            s+=500;
        B[i]=s;
    }
}

int main()
{
    bin();
    //freopen("in.txt","r",stdin);
    char a[10][30]={{"........||.../\\..."},
                    {"........||../..\\.."},
                    {".../\\...||./....\\."},
                    {"../..\\..||/G.....\\"},//3,11
                    {"./....\\.||\\______/"},
                    {"/YQYFU.\\||........"},//5,1
                    {"\\______/||........"} };

    char b[10][30]={{".../\\...||........"},
                    {"../..\\..||........"} ,
                    {"./....\\.||.../\\..."} ,
                    {"/WCGQG.\\||../..\\.."} ,//3,1
                    {"\\______/||./....\\."} ,
                    {"........||/OYA...\\"},//5,11
                    {"........||\\______/"} };


    char c[10][30]={{"........||........"},
                    {".../\\...||.../\\..."},
                    {"../..\\..||../..\\.."},
                    {"./....\\.||./....\\."},
                    {"/NQ....\\||/FG....\\"},//4,1//4,11
                    {"\\______/||\\______/"},
                    {"........||........"}};
                    //printf("%c",c[4][11]);
    //for(int i=0;i<8;i++)
        //cout<<a[i]<<endl;
        int tc,i,s1,s2,t=1;
        char x[10][50];
        scanf("%d",&tc);
        while(tc--)
        {

            for(i=0;i<8;i++)
                scanf("%s",x[i]);
            printf("Case %d:\n",t++);
            s1=s2=0;
            if(x[5][1]=='_')
            {

                for(i=1;i<=6;i++)
                    if(isalpha(x[4][i]))
                    s1+=B[x[4][i]];
                for(i=11;i<=16;i++)
                    if(isalpha(x[4][i]))
                    s2+=B[x[4][i]];
                //printf("%d %d\n",s1,s2);
                if(s1==s2)
                    printf("The figure is correct.\n");

                else if(s1<s2)
                {
                    for(i=1;i<=6;i++)
                        b[3][i]=x[4][i];
                    for(i=11;i<=16;i++)
                        b[5][i]=x[4][i];
                    for(int i=0;i<7;i++)
                      cout<<b[i]<<endl;
                }
                else
                {
                    for(i=1;i<=6;i++)
                        a[5][i]=x[4][i];
                    for(i=11;i<=16;i++)
                        a[3][i]=x[4][i];
                    for(int i=0;i<7;i++)
                      cout<<a[i]<<endl;
                }
            }
            else if(x[6][1]=='_')
            {
                for(i=1;i<=6;i++)
                    if(isalpha(x[5][i]))
                    s1+=B[x[5][i]];
                for(i=11;i<=16;i++)
                    if(isalpha(x[3][i]))
                    s2+=B[x[3][i]];
                if(s1>s2)
                    printf("The figure is correct.\n");
                else if(s1<s2)
                {
                    for(i=1;i<=6;i++)
                        b[3][i]=x[5][i];
                    for(i=11;i<=16;i++)
                        b[5][i]=x[3][i];
                    for(int i=0;i<7;i++)
                      cout<<b[i]<<endl;
                }
                else
                {
                    for(i=1;i<=6;i++)
                        c[4][i]=x[5][i];
                    for(i=11;i<=16;i++)
                        c[4][i]=x[3][i];
                    for(int i=0;i<7;i++)
                      cout<<c[i]<<endl;
                }
            }
            else
            {
                for(i=1;i<=6;i++)
                    if(isalpha(x[3][i]))
                    s1+=B[x[3][i]];
                for(i=11;i<=16;i++)
                    if(isalpha(x[5][i]))
                    s2+=B[x[5][i]];
                if(s1<s2)
                    printf("The figure is correct.\n");
                else if(s1>s2)
                {
                    for(i=1;i<=6;i++)
                        a[5][i]=x[3][i];
                    for(i=11;i<=16;i++)
                        a[3][i]=x[5][i];
                    for(int i=0;i<7;i++)
                      cout<<a[i]<<endl;
                }
                else
                {
                    for(i=1;i<=6;i++)
                        c[4][i]=x[3][i];
                    for(i=11;i<=16;i++)
                        c[4][i]=x[5][i];
                    for(int i=0;i<7;i++)
                      cout<<c[i]<<endl;
                }
            }


        }
        return 0;
}
