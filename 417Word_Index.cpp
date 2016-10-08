#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int len,num,i,x,y;
    char w[1000];
    x=26;
    bool f;
    while(scanf("%s",w)==1)
    {
        f=false;
        len=strlen(w);
        num=0;
        x=0;
        y=0;
        for(i=0;i<len;i++)
        {
            //num+=(((w[i]-'A')+1)*26);
            num+=(((int)(pow(26,len-1-i))*(w[i]-'a'+1)));
            if(f==true)
            {
                num-=(pow(26,x)+(w[i]-'a')%26);
                x++;
                //y+=2;
            }
            f=true;
            //x--;
        }
        printf("%d\n",num);
    }
    return 0;
}
