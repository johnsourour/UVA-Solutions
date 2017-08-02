#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vi primes;
ll _sieve_size; 
bitset<10000010> bs; 
map<ll,int> mp;
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
int primeFactors(ll N) 
{
	vi pFactors;
	int cnt=0;
	ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
	while (PF * PF <= N) 
	{
		while (N % PF == 0) { N /= PF; mp[PF]++; cnt++;} 
		PF = primes[++PF_idx]; // only consider primes!
	}
	if (N != 1) 
	{
		cnt++;
		mp[N]++;
	}
	return cnt;
} 
bool can(ll n1, ll n2)
{
	mp.clear();
	int cnt=primeFactors(n2);
	bool valid=true;
	for(map<ll,int>::iterator it=mp.begin();it!=mp.end();++it)
	{
		ll cur=(*it).first;
		while(cur<=n1 && (*it).second)
		{
			ll tmp=cur;
			while((*it).second && tmp%(*it).first==0)
			{
				cnt--;
				tmp/=(*it).first;
				(*it).second--;
			}
			cur+=(*it).first;
		}
		if((*it).second)break;
	}
	return !cnt;
}
int main()
{
	sieve(1000000);
	ll a,b;
	while(scanf("%lld%lld",&a,&b)!=EOF)
	{
		printf("%lld",b);
		if(can(a,b))printf(" divides ");
		else printf(" does not divide ");
		printf("%lld!\n",a);
	}
}
