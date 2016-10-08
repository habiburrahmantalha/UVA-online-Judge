#include<stdio.h>
int a[11];
bool ordered_asc()
{
    for(int i=0;i<9;i++)
    {
        if(a[i]>a[i+1])
            return false;
    }
    return true;
}
bool ordered_dec()
{
    for(int i=0;i<9;i++)
    {
        if(a[i]<a[i+1])
            return false;
    }
    return true;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    printf("Lumberjacks:\n");
    while(tc--)
    {
        for(int i=0;i<10;i++)
            scanf("%d",&a[i]);

        if(a[0]>a[1])
        {
            if(ordered_dec())
            printf("Ordered\n");
            else
            printf("Unordered\n");
        }
        else
        {
            if(ordered_asc())
            printf("Ordered\n");
            else
            printf("Unordered\n");
        }
    }
    return 0;
}

