#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
ll _sieve_size; 
bitset<10000010> bs; 
vi primes; 
void sieve(ll upperbound) 
{ 
	_sieve_size = upperbound + 1;
	bs.set(); 
	bs[0] = bs[1] = 0; 
	for (ll i = 2; i <= _sieve_size; i++) 
	if (bs[i]) 
	{
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}
map<ll,vi> mp;
ll sumDiv(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1; 
	while (PF * PF <= N) {
		ll power = 0;
		while (N % PF == 0) { N /= PF; power++; }
		ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
		PF = primes[++PF_idx];
	}
	if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); 
	return ans;
}
void gen(int n)
{
	for(int i=1;i<=n;i++)
	{
		ll cur=sumDiv(i);
		mp[cur].push_back(i);
	}
	for(map<ll,vi>::iterator it=mp.begin();it!=mp.end();++it)
	{
		sort((*it).second.begin(),(*it).second.end());
	}
}
int main()
{
	ll n;
	int K=1;
	sieve(1000);
	gen(1000);
	while(scanf("%lld",&n)!=EOF && n)
	{
		ll ans=mp[n].size()?mp[n].back():-1;
		printf("Case %d: %lld\n",K++,ans);
	}
}
