#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005

typedef long long ll;
typedef vector<int> vi;
ll _sieve_size; 
bitset<10000010> bs; 
vi primes, NOD; 
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

int numDiv(int N) {
	int PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1
	while (PF * PF <= N) {
		int power = 0; // count the power
		while (N % PF == 0) { N /= PF; power++; }
		ans *= (power + 1); // according to the formula
		PF = primes[++PF_idx];
	}
	if (N != 1) ans *= 2; // (last factor has pow = 1, we add 1 to it)
	return ans;
}
void gen(){
	NOD[0]=1;
	for(int i=1;i<MAX;i++){
		NOD[i]=NOD[i-1]+numDiv(NOD[i-1]);
	}
	
}
int main()
{
	sieve(MAX);
	int K=0;
	NOD.resize(MAX);
	gen();
	int T, A, B;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&A,&B);
		int down = lower_bound(NOD.begin(),NOD.end(),A) - NOD.begin();
		int up = lower_bound(NOD.begin(),NOD.end(),B) - NOD.begin();
		
		if(NOD[up]>B)up--;
		//cout<<NOD[down]<<" "<<NOD[up]<<endl;
		printf("Case %d: %d\n",++K,up-down+1);
		
	}

}
