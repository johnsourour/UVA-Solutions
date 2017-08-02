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
vi primeFactors(ll N) 
{
	vi pFactors;
	ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
	while (PF * PF <= N) 
	{
		while (N % PF == 0) { N /= PF; pFactors.push_back(PF); } 
		PF = primes[++PF_idx]; // only consider primes!
	}
	if (N != 1) pFactors.push_back(N); 
	return pFactors;
} 
int main()
{
	ll n;
	vi ans;
	bool neg,first;
	sieve(1000000);
	while(scanf("%lld",&n)!=EOF && n)
	{
		neg=n<0;
		ans=primeFactors(abs(n));
		printf("%lld",n);
		if(neg) 
		{
			first=false;
			printf(" = -1");
		}
		else first=true;
		for(vi::iterator it=ans.begin();it!=ans.end();++it)
		{
			if(first)
			{
					printf(" = %lld",*it);
				first=false;
			}
			
			else
			printf(" x %lld",*it);
		}
		printf("\n");
		
	}
}
