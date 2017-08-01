#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<10000010> bs;  
ll _sieve_size;
void sieve(ll upperbound) 
{ 
	_sieve_size = upperbound + 1;
	bs.set(); 
	bs[0] = bs[1] = 0; 
	for (ll i = 2; i <= _sieve_size; i++) 
	if (bs[i]) 
	{
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
	}
}
int main()
{
	sieve(1000000);
	int N;
	while(scanf("%d",&N)!=EOF && N)
	{
		int i;
		for(i=N-2;i>=2;i--)if(bs[i] && bs[N-i]){
			break;
		}
		printf("%d = %d + %d\n",N,N-i,i);
	}
	return 0;
}
