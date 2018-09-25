#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1300
#define MAX_P 215
#define MAX_K 15
typedef vector<int> vi;
int _sieve_size; 
bitset<MAX_N> bs; 
vi primes; 
void sieve(int upperbound) 
{ 
	_sieve_size = upperbound + 1;
	bs.set(); 
	bs[0] = bs[1] = 0; 
	for (int i = 2; i <= _sieve_size; i++) 
	if (bs[i]) 
	{
		for (int j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}
int mem[MAX_P][MAX_N][MAX_K];
int numWays(int idx, int cur, int k){
	if(k==0)return cur==0;
	if(idx>=MAX_P || cur<=0 || k<0 || cur<primes[idx])return 0;
	if(mem[idx][cur][k]==-1){
		mem[idx][cur][k]=numWays(idx+1, cur-primes[idx], k-1)+numWays(idx+1,cur,k);	
	}
	return mem[idx][cur][k];
}
int main()
{
	int n,k;
	sieve(MAX_N);
	while(scanf("%d%d",&n,&k) && (n||k)){
		memset(mem, -1, sizeof mem);
		printf("%d\n",numWays(0, n, k));
	}
}
