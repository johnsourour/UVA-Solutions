#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,d;
void extendedEuclid(ll a,ll b) {
	if (b == 0) { x = 1; y = 0; d = a; return; } 
	extendedEuclid(b, a % b); 
	ll x1 = y;
	ll y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}
int main()
{
	ll n,c1,c2,n1,n2;
	while(scanf("%lld",&n)!=EOF && n)
	{
		scanf("%lld%lld%lld%lld",&c1,&n1,&c2,&n2);
		bool swapped=false;
		if(1.0*c1/n1>1.0*c2/n2)
		{
			swap(c1,c2);
			swap(n1,n2);
			swapped =true;
		}
		extendedEuclid(n1,n2);
		if(n%d!=0)printf("failed\n");
		else
		{
			ll mul=n/d;
			x*=mul;y*=mul;
			ll nn1=ceil(1.0*-x*d/n2);
			ll nn2=floor(1.0*y*d/n1);
			if(nn1<=nn2)
			{
				x+=(n2/d*nn2);
				y-=(n1/d*nn2);
				if(swapped)swap(x,y);
				printf("%lld %lld\n",x,y);
			}
			else 
			{
				printf("failed\n");
			}
		}
	
	}
}
