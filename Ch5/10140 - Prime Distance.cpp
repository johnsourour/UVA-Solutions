#include<bits/stdc++.h>
using namespace std;
#define MAX 10000010
typedef long long ll;
typedef vector<ll> vi;
ll _sieve_size;
bitset<MAX> bs; 
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

bool isPrime(ll N)
{ 
	if (N <= _sieve_size) return bs[N]; 
	for (int i = 0; i < (int)primes.size(); i++)
	{
		if (N % primes[i] == 0) return false;
		if (primes[i] > sqrt(N))return true;
	}
	return true; 
} 
int main()
{
	//cout<<1<<endl;
	sieve(MAX);
	ll L,U;
	while(scanf("%lld%lld",&L,&U)!=EOF)
	{
		bool exist=false;
		ll prev=-1,mx=-1,mn=1e9;
		ll s1,s2,b1,b2;
		
		for(ll i=L;i<=U;i++)
		{
			if(isPrime(i))
			{
				if(prev!=-1)
				{
					exist=true;
					if(i-prev<mn)
					{
						mn=i-prev;
						s1=prev;
						s2=i;
					}
					if(i-prev>mx)
					{
						mx=i-prev;
						b1=prev;
						b2=i;
					}
				}
				prev=i;
			}
		}
		if(!exist)
		printf("There are no adjacent primes.\n");
		else
		printf("%lld,%lld are closest, %lld,%lld are most distant.\n",s1,s2,b1,b2);
	}
	return 0;
}
