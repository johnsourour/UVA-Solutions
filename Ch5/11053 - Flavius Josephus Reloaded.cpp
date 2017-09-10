#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
ll N,a,b;
int f(ll x){
	ll ans=(x*x)%N;
	ans=(ans*a)%N;
	ans=(ans+b)%N;
	return ans;
}
ii floydCycleFinding(int x0) 
{
	int tortoise = f(x0), hare = f(f(x0)); 
	while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
	int mu = 0; hare = x0;
	while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;}
	int lambda = 1; hare = f(tortoise);
	while (tortoise != hare) { hare = f(hare); lambda++; }
	return ii(mu, lambda);
}
int main()
{

	while(cin>>N>>a>>b && N)
	{
		printf("%d\n",N-floydCycleFinding(0).second);
	}
}
