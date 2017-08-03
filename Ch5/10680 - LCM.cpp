#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
typedef long long ll;
typedef vector<ll> vi;
ll _sieve_size; 
bitset<1000010> bs; 
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
		primes.push_back(i);
	}
}
void keep(ll &n)
{
	while(n%10==0)
	{
		n/=10;
	}
	n%=100000000;
}

vi primeFactors(int N) 
{
	vi factors;
	int PF_idx = 0, PF = primes[PF_idx]; 
	while (PF <= N) 
	{
		ll cur=PF;
		while (cur*PF <=N && cur<MAX) { cur *= PF; } 
		factors.push_back(cur);
		PF = primes[++PF_idx]; 
	}
	return factors;
} 
int main()
{
	sieve(MAX);
	int N;
	while(scanf("%d",&N)!=EOF && N)
	{
		vi factors=primeFactors(N);
		ll ans=1;
		for(ll k:factors)
		{
			if(k>MAX)cout<<k<<endl;
			ans*=k;
			keep(ans);
		}
		printf("%d\n",ans%10);
	}
	return 0;
}
