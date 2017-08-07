#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	while(scanf("%lld",&n)!=EOF && n)
	{
		ll s=sqrt(n);
		if(s*s==n)printf("yes\n");
		else printf("no\n");
	}
}
