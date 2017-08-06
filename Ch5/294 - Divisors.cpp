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
ll numDiv(ll N) 
{
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1; 
	while (PF * PF <= N) {
		ll power = 0;
		while (N % PF == 0) { N /= PF; power++; }
		ans *= (power + 1); 
		PF = primes[++PF_idx];
	}
	if (N != 1) ans *= 2; 
	return ans;
}
int main()
{
	ll mxi,mx,L,U;
	sieve(10000000);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&L,&U);
		mx=0;
		mxi=-1;
		for(ll i=L;i<=U;i++)
		{
			ll cur=numDiv(i);
			if(cur>mx)
			{
				mx=cur;
				mxi=i;
			}
		}
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",L,U,mxi,mx);
	}
}
