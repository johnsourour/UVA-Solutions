#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vi primes;
map<ll,int> ms;
ll _sieve_size; 
bitset<10000010> bs; 
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
ll LPD(ll N) 
{
	ll last=-1;
	int diff=0;
	ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
	while (PF * PF <= N) 
	{
		if(N % PF == 0)diff++;
		while (N % PF == 0) { N /= PF; last=PF;} 
		PF = primes[++PF_idx]; 
	}
	if(N>1){
		diff++;last=N;
	}
	return diff>1?last:-1;
} 
int main()
{
	ll n;
	sieve(10000000);
	while(scanf("%lld",&n)!=EOF && n)
	{
		n=abs(n);
		ll ans=LPD(n);
		printf("%lld\n",ans==n?-1:ans);
	}
}
