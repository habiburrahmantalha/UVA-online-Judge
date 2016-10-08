#include<stdio.h>
#include<string.h>

int main()
{
    freopen("in.txt","r",stdin);
  char s[100000],c;
  int i,j,k;


//  while(cases--)
  {
    i=0;
    while((c=getchar()))
    {
        if(c==EOF)
        break;
        if(c=='\n')
        {
            for(k=i-1;k>=0;k--)
            printf("%c",s[k]);
            i=0;
            printf("\n");
        }
       if(c==' ')
       {
            for(k=i-1;k>=0;k--)
            printf("%c",s[k]);
            i=0;
            printf(" ");
       }
        if(c!=' ' && c!='\n')
        s[i++]=c;
    }



  }

return 0;
}
