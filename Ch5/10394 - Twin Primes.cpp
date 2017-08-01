#include<bits/stdc++.h>
using namespace std;
#define MAX 20000000
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
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
	//	primes.push_back(i);
	}
}
int main()
{
	//cout<<1<<endl;
	sieve(MAX);
	ll L,U;
	vector<ii> tw;
	ll cur=2,cnt=0;
	bool prev=false;
	while(cnt<100000)
	{
		//cout<<cur<<" "<<cur+2<<endl;
		if(bs[cur]&& bs[cur+2])
		{
			tw.push_back(ii(cur,cur+2));
			cnt++;
			cur+=2;
			
		}
		else 
		{
		cur++;
		}
	}
	int S;
	while(scanf("%d",&S)!=EOF)
	{
		S--;
		printf("(%lld, %lld)\n",tw[S].first,tw[S].second);
	}
	return 0;
}
