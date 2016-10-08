#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
typedef vector<string> VS;
int n;



VS rotate_90(VS v)
{
    int i,j;
    string s;
    VS x;
    for(i=n-1;i>=0;i--)
    {
        s="";
        for(j=0;j<n;j++)
        s+=v[j][i];
        x.push_back(s);
    }
    return x;

}
VS rotate_v(VS v)
{
    VS x;
    int i,j;
    for(i=n-1;i>=0;i--)
    x.push_back(v[i]);

    return x;

}
void print(VS v)
{
    int i;
    for(i=0;i<n;i++)
        cout<<v[i]<<endl;

}
int main()
{
    VS v1,v2,v3;
    string s1,s2;
    int t=1,i;
    while(scanf("%d",&n)==1)
    {
        v1.clear();
        v2.clear();
        for(i=0;i<n;i++)
        {
            cin>>s1>>s2;
            v1.push_back(s1);
            v2.push_back(s2);
        }
        v3=v2;
        if(v1==v2)
        printf("Pattern %d was preserved.\n",t++);
        else
        {
            v2=rotate_90(v2);
            if(v1==v2)
            printf("Pattern %d was rotated 90 degrees.\n",t++);
            else
            {
                v2=rotate_90(v2);
                if(v1==v2)
                printf("Pattern %d was rotated 180 degrees.\n",t++);
                else
                {
                    v2=rotate_90(v2);
                    if(v1==v2)
                    printf("Pattern %d was rotated 270 degrees.\n",t++);
                    else
                    {
                        v3=rotate_v(v3);
                        if(v1==v3)
                        printf("Pattern %d was reflected vertically.\n",t++);
                        else
                        {
                            v3=rotate_90(v3);
                            if(v1==v3)
                            printf("Pattern %d was reflected vertically and rotated 270 degrees.\n",t++);
                            else
                            {
                                v3=rotate_90(v3);
                                if(v1==v3)
                                printf("Pattern %d was reflected vertically and rotated 180 degrees.\n",t++);
                                else
                                {
                                    v3=rotate_90(v3);
                                    if(v1==v3)
                                    printf("Pattern %d was reflected vertically and rotated 90 degrees.\n",t++);
                                    else
                                    printf("Pattern %d was improperly transformed.\n",t++);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
