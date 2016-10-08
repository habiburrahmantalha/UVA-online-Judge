//n log k solution  .040 sec
#include <vector>
#include<stdio.h>
using namespace std;

vector<int>a;

void LIS()
{
	vector<int> b, p(a.size());
	int u, v;


	b.push_back(0);

	for (int i = 1; i < (int)a.size(); i++) {
		if (a[b.back()] < a[i]) {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}

		for (u = 0, v = b.size()-1; u < v;) {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}

		if (a[i] < a[b[u]]) {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}
	}
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;

    printf("%d\n-\n",b.size());
	for (v=0;v<b.size();v++)
	printf("%d\n",a[b[v]]);

}


int main()
{
    //freopen("in.txt","r",stdin);
    int x;

    while(scanf("%d",&x)==1)
    {
        a.push_back(x);
    }
    LIS();

    return 0;
}
