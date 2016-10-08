#include<stdio.h>
#include<string.h>

int main ()
{
    int coins [] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
    double change [6010];

    memset (change, 0, sizeof (change));

    change[0] = 1;

    for ( int i = 0; i < 11; i++ )
    {
        for ( int j = 1; j <= 6000; j++ )
        {
            if ( j - coins [i] >= 0 )
                change [j] += change[j - coins [i]];
        }
    }

    double c;

    while ( scanf ("%lf", &c) )
    {
        if ( c == 0 ) break;
        int index = c * 20;

        printf ("%6.2lf%17.lf\n", c, change[index]);
    }

    return 0;
}


