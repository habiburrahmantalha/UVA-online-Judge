#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<ctype.h>
#include<sstream>
using namespace std;
struct F1
{
    char name[25];
    char cs_name[25];
    int time;
};
bool comp(F1 i,F1 j)
{

    if(i.time==j.time)
    {
        int l1,l2,k;
        l1=strlen(i.cs_name);
        l2=strlen(j.cs_name);
        if(l1<=l2)
        {
            for(k=0;k<l1;k++)
                if(i.cs_name[k]!=j.cs_name[k])
                    return i.cs_name[k]< j.cs_name[k];
            return strlen(i.cs_name)<strlen(j.cs_name);
        }
        else
        {
            for(k=0;k<l2;k++)
                if(i.cs_name[k]!=j.cs_name[k])
                    return i.cs_name[k]< j.cs_name[k];
            return strlen(i.cs_name)<strlen(j.cs_name);
        }


    }
        /*
        {if(strcmp(i.cs_name , j.cs_name)==0)
            return strlen(i.cs_name)<strlen(j.cs_name);
        else
            return strcmp(i.cs_name , j.cs_name);
        }
        */
    else
        return (i.time < j.time);
}

int main()
{
    int n,i,j,m,s,ms,row;
    F1 driver[101];
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s : %d min %d sec %d ms",driver[i].name,&m,&s,&ms);
            driver[i].time=((m*60*100)+(s*100)+ms);

            for(j=0;j<strlen(driver[i].name);j++)
            if(isalpha(driver[i].name[j]))
                driver[i].cs_name[j]=tolower(driver[i].name[j]);
            else
                driver[i].cs_name[j]=driver[i].name[j];
            driver[i].cs_name[j]=0;
        }

        sort(driver,driver+n,comp);

        row=1;
        for(i=0;i<n;i+=2)
        {
            printf("Row %d\n",row++);
            printf("%s\n",driver[i].name);
            if(i+1<n)
                printf("%s\n",driver[i+1].name);
        }
        printf("\n");
    }
    return 0;
}
