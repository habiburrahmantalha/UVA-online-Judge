#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;


int gy[30][30],gm[30][30];

void warshal_Y()
{
    int i,j,k;
    for(k=0;k<=26;k++)
        for(i=0;i<=26;i++)
            for(j=0;j<=26;j++)
                gy[i][j]=min(gy[i][j],gy[i][k]+gy[k][j]);
}

void warshal_M()
{
    int i,j,k;
    for(k=0;k<=26;k++)
        for(i=0;i<=26;i++)
            for(j=0;j<=26;j++)
                gm[i][j]=min(gm[i][j],gm[i][k]+gm[k][j]);
}
void reset_Y()
{
    int i,j;
    for(i=0;i<=26;i++)
        for(j=0;j<=26;j++)
        gy[i][j]=100000;
}
void reset_M()
{
    int i,j;
    for(i=0;i<=26;i++)
        for(j=0;j<=26;j++)
        gm[i][j]=100000;
}
int main()
{
    int c;
    char a[2],d[2],s[2],e[2];
    int i,j,min_enrg,n;
    while(scanf("%d",&n) && n)
    {
        //memset(gy,0x7F,sizeof(gy));
        //memset(gm,0x7F,sizeof(gm));
        reset_M();
        reset_Y();

        for(i=0;i<n;i++)
        {
            scanf("%s %s %s %s %d",a,d,s,e,&c);
            if(a[0]=='Y')
            {
                if(d[0]=='U')
                gy[s[0]-'A'][e[0]-'A']=min(c,gy[s[0]-'A'][e[0]-'A']);
                else
                {
                    gy[s[0]-'A'][e[0]-'A']=min(c,gy[s[0]-'A'][e[0]-'A']);
                    gy[e[0]-'A'][s[0]-'A']=min(c,gy[s[0]-'A'][e[0]-'A']);

                }
            }
            else
            {
                if(d[0]=='U')
                gm[s[0]-'A'][e[0]-'A']=min(c,gm[s[0]-'A'][e[0]-'A']);
                else
                {
                    gm[s[0]-'A'][e[0]-'A']=min(c,gm[s[0]-'A'][e[0]-'A']);
                    gm[e[0]-'A'][s[0]-'A']=min(c,gm[s[0]-'A'][e[0]-'A']);
                }

            }
        }
        warshal_M();
        warshal_Y();
        /*
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%7d",gy[i][j]);
            printf("\n");
        }
        printf("\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%7d",gm[i][j]);
            printf("\n");
        }
        */
        scanf("%s %s",s,e);
        min_enrg=100000;
        //if(s[0]==e[0])
        {
            //printf("0 %s\n",s);
            gy[s[0]-'A'][s[0]-'A']=0;
            gm[e[0]-'A'][e[0]-'A']=0;
        }
        //else
        {
            for(i=0;i<=26;i++)
            {
                if(gy[s[0]-'A'][i]!=100000 && gm[e[0]-'A'][i]!=100000)
                    if(min_enrg>(gy[s[0]-'A'][i] + gm[e[0]-'A'][i]))
                        min_enrg=(gy[s[0]-'A'][i] + gm[e[0]-'A'][i]);

            }
            if(min_enrg!=100000)
            {
                printf("%d",min_enrg);
                for(i=0;i<=26;i++)
                {
                    if(gy[s[0]-'A'][i]!=100000 && gm[e[0]-'A'][i]!=100000)
                        if(min_enrg==(gy[s[0]-'A'][i] + gm[e[0]-'A'][i]))
                            printf(" %c",i+'A');
                }
                printf("\n");
            }
            else
                printf("You will never meet.\n");
        }
    }
    return 0;
}
