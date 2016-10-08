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
double x[1010],y[1010];
int n;
double dist(int i,int j)
{
	double R = 6371; //radious of earth
	double lat1=x[i];
	double lat2=x[j];
	double lon1=y[i];
	double lon2=y[j];
	double dLat = (lat2-lat1) * PI / 180;//radious
	double dLon = (lon2-lon1) * PI / 180;
	double a = sin(dLat/2) * sin(dLat/2) +
               cos(lat1 * PI / 180 ) * cos(lat2 * PI / 180 ) *
		sin(dLon/2) * sin(dLon/2);
	double c = 2 * atan2(sqrt(a),sqrt(1-a));
	double d = R * c;

	return d;
}

int main()
{
    int i,j;
    double mx,X,Y,mn;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        scanf("%lf %lf",&x[i],&y[i]);

        mn=20000000.0;
        for(i=0;i<n;i++)
        {
            mx=0.0;
            for(j=0;j<n;j++)
            {
               mx=max(mx,dist(i,j));
            }
            if(mx<=mn)
            {
                mn=mx;
                X=x[i];
                Y=y[i];
            }
        }
        printf("%.2lf %.2lf\n",X,Y);
    }
    return 0;
}
