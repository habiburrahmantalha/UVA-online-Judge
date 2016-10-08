#include<stdio.h>

int ug(int s,int m)
{

    int seed=0,count=0;
    while(1)
        {
            seed=(seed+s)%m;
            count++;
            if(seed == 0)
            break;


        }
        return count;
}

int main()
{
    int mod,step,i,count;
    bool f;

    while(scanf("%d %d",&step,&mod)==2)
    {
        f=true;
        count=ug(step,mod);

        if(count==mod)
        printf("%10d%10d    Good Choice\n\n",step,mod);
        else
        printf("%10d%10d    Bad Choice\n\n",step,mod);

    }

    return 0;

}
