#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
vi primes;
map<int,ii> mp;
ll _sieve_size; 
bitset<1000010> bs; 
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.first <= j.first;
}
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
void primeFactors(ll N,bool big) 
{
	ll PF_idx = 0, PF = primes[PF_idx]; 
	while (PF * PF <= N) 
	{
		int cnt=0;
		while (N % PF == 0) { N /= PF; big?mp[PF].first++:mp[PF].second++; } 
		PF = primes[++PF_idx]; 
	}
	if (N != 1) big?mp[N].first++:mp[N].second++;
} 
int solve(int a, int c)
{
	mp.clear();
	primeFactors(c,1);
	primeFactors(a,0);
	ll ans=1;
	vector<ii> f,s;
	for(map<int,ii>::iterator it=mp.begin();it!=mp.end();++it)
	{
		if((*it).second.first)f.push_back(ii((*it).first,(*it).second.first));
		if((*it).second.second)s.push_back(ii((*it).first,(*it).second.second));
	}
	sort(f.begin(),f.end(),compare);
	sort(s.begin(),s.end(),compare);
	int i=0,j=0;
	while(i<f.size() && j<s.size())
	{
		if(s[j].first==f[i].first){
			if(s[j].second>f[i].second)break;
			else if(s[j].second<f[i].second)ans*=pow(f[i].first,f[i].second);
			i++;j++;
			}
		else if(s[j].first<f[i].first){
			j++;
		}
		else {
			ans*=pow(f[i].first,f[i].second);i++;
		}
	}
	while(i<f.size()){ans*=pow(f[i].first,f[i].second);i++;}
	return ans;
}
int main()
{
	sieve(1000000);
	int T,A,C;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&A,&C);
		if(C%A)printf("NO SOLUTION\n");
		else printf("%d\n",solve(A,C));
	}
}
