#include<stdio.h>
#include<string>

void card_divide()
{

    for(i=0;i<10;i++)
    {
        if(isdigit(card[i][0]))
            in=card[i][0]-47;
        else
        {
            if(card[i][0]=='T')
                in=10;
            else if(card[i][0]=='J')
                in=11;
            else if(card[i][0]=='Q')
                in=12;
            else if(card[i][0]=='K')
                in=13;
        }

        if(card[i][1]=='S')
        {
            S[in]=1;
            s++;
        }
        else if(card[i][1]=='H')
        {
            H[in]=1;
            h++;
        }
        else if(card[i][1]=='C')
        {
            C[in]=1;
            c++;
        }
        else if(card[i][1]=='D')
        {
            D[in]=1;
            d++;
        }
    }
}


int main()
{
    while(sacnf("%s",card[0])==1)
    {
        for(i=1;i<10;i++)
            scanf("%s",card[i]);


    }
    return 0;
}
