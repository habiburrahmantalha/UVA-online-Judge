#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
    int t=1,tc,cy,cm,cd,d,m,y,age;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d/%d/%d",&cd,&cm,&cy);
        scanf("%d/%d/%d",&d,&m,&y);

        if(cy<y)
            printf("Case #%d: Invalid birth date\n",t++);
        else
        {
            age=0;
            while(y<cy)
            {
                age++;
                y++;
            }
            if(cm<m)
            age--;
            else if(cm==m)
            {
                if(cd<d)
                age--;
            }
            if(age>130)
            printf("Case #%d: Check birth date\n",t++);
            else if(age<0)
            printf("Case #%d: Invalid birth date\n",t++);
            else
            printf("Case #%d: %d\n",t++,age);
        }
    }

    return 0;
}
