#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 300
#define MAX_L 1005
ll mem[MAX_N+1][MAX_N+1][MAX_L+1];
ll DP(int rem, int cur, int count){
	if(rem<0 || cur>MAX_N || count<0)return 0;
	if(rem==0)return count==0;
	if(mem[rem][cur][count]==-1){
		mem[rem][cur][count]=DP(rem-cur,cur,count-1)+DP(rem,cur+1,count);	
	}
	return mem[rem][cur][count];
}
int main()
{
	int tmp, n, l1, l2;
	string s;
	memset(mem,-1, sizeof mem);
	while(getline(cin,s)){
		vector<int> in;
		istringstream iss(s);
		while(iss>>tmp)in.push_back(tmp);
		n=in[0];
		l1 = in.size()==3? in[1] : 0;
		l2 = in.size()>1? (in.size()==3?in[2]:in[1]) : MAX_L;
		
		ll ans=0;
		for(int i=l1;i<=l2;i++)ans+=DP(n,1,i);
		printf("%lld\n",ans);
		
	}
}
