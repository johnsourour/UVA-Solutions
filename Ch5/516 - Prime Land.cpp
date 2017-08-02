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
void primeFactors(ll N) 
{
	ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
	while (PF * PF <= N) 
	{
		while (N % PF == 0) { N /= PF; ms[PF]++; } 
		PF = primes[++PF_idx]; // only consider primes!
	}
	if (N != 1) ms[N]++; 
} 
int main()
{
	sieve(1000000);
	string s;
	ll v,cur,num;
	while(getline(cin,s) && s!="0")
	{
		istringstream iss(s);
		bool exp=false;
		num=1;
		while(iss>>v)
		{
			if(!exp)
			{
				cur=v;
			}
			else
			{
				num*=pow(cur,v);
			}
			exp=!exp;
		}
		ms.clear();
		primeFactors(num-1);
		bool first=true;
		for(map<ll,int>::reverse_iterator it=ms.rbegin();it!=ms.rend();++it)
		{
			if(!first)printf(" ");
			first=false;
			printf("%lld %d",(*it).first,(*it).second);
		}
		printf("\n");
		
	}
}
