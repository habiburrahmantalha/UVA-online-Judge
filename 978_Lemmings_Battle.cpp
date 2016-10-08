//Problem Type : adhoc
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)


int main()
{
    priority_queue<int>QSG,QSB;
    queue<int>sg,sb;
    int a,b,B,SG,SB,i,x,tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&B,&SG,&SB);
        for(i=0;i<SG;i++)
        {
            scanf("%d",&x);
            QSG.push(x);
        }

        for(i=0;i<SB;i++)
        {
            scanf("%d",&x);
            QSB.push(x);
        }
        while(!QSG.empty() && !QSB.empty())
        {
            for(i=0;i<B;i++)
            {
                if(QSG.empty() || QSB.empty())
                break;

                a=QSG.top();QSG.pop();
                b=QSB.top();QSB.pop();
                if(a<b)
                {
                    b=b-a;
                    sb.push(b);
                    a=0;
                }
                else if(a>b)
                {
                    a=a-b;
                    sg.push(a);
                    b=0;
                }
                else
                {
                    a=b=0;
                }

            }
            while(!sg.empty())
            {
                a=sg.front();sg.pop();
                QSG.push(a);
            }
            while(!sb.empty())
            {
                b=sb.front();sb.pop();
                QSB.push(b);
            }
        }
        if(QSG.empty() && QSB.empty())
            printf("green and blue died\n");
        else if(QSG.empty())
        {
            printf("blue wins\n");
            while(!QSB.empty())
            {
                b=QSB.top();QSB.pop();
                printf("%d\n",b);
            }
        }
        else
        {
            printf("green wins\n");
            while(!QSG.empty())
            {
                a=QSG.top();QSG.pop();
                printf("%d\n",a);
            }

        }
        if(tc)
        printf("\n");

    }
    return 0;
}
