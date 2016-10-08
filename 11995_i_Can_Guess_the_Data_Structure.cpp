#include<queue>
#include<stack>
#include<stdio.h>

using namespace std;

int main()
{
    int n,o,x,i,a,b,c;

    bool fq,fs,fpq;
    while(scanf("%d",&n)==1)
    {
        queue<int> q;
        priority_queue<int> pq;
        stack<int> s;

        fq=true;
        fs=true;
        fpq=true;

        for(i=0;i<n;i++)
        {
            scanf("%d %d",&o,&x);
            if(o==1)
            {
                q.push(x);
                pq.push(x);
                s.push(x);
            }
            else
            {
                if(q.empty())
                fq=false;
                else
                a=q.front();

                if(pq.empty())
                fpq=false;
                else
                b=pq.top();

                if(s.empty())
                fs=false;
                else
                c=s.top();

                if(fq && x==a)
                    q.pop();
                else
                    fq=false;

                if(fpq && x==b)
                    pq.pop();
                else
                    fpq=false;

                if(fs && x==c)
                    s.pop();
                else
                    fs=false;
            }
        }
        if(fq && !fs && !fpq)
            printf("queue\n");
        else if(!fq && fs && !fpq)
            printf("stack\n");
        else if(!fq && !fs && fpq)
            printf("priority queue\n");
        else if(!fq && !fs && !fpq)
            printf("impossible\n");
        else
            printf("not sure\n");

    }
    return 0;
}
