#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x,y,d;
void extendedEuclid(int a, int b) {
	if (b == 0) { x = 1; y = 0; d = a; return; } 
	extendedEuclid(b, a % b); 
	int x1 = y;
	int y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}
int main()
{
	int T,a,b,n,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		extendedEuclid(floor(1.0*n/k),ceil(1.0*n/k));
		printf("%d %d\n",x*n/d,y*n/d);
	}
}
