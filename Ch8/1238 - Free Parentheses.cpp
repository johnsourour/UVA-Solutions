#include<bits/stdc++.h>
using namespace std;

#define OFFSET 2975
#define MAX_P 35
#define MAX_N 3000+OFFSET

bool mem[MAX_P][MAX_P][MAX_N], sign[MAX_P], vis[MAX_N+1];
int num[MAX_P], n;

void DP(int idx, int open, int cur){
	
	int ncur = cur + OFFSET;
	
	if(idx==n){
		vis[ncur]=true;
		return;
	}
	
	if(!mem[idx][open][ncur]){
		int nxt = num[idx];
		int rev = sign[idx]+open;
		
		if(rev%2)nxt=-nxt;
		
		if(sign[idx])
			DP(idx+1, open+1, nxt+cur);
		
		if(open>0)
			DP(idx+1, open-1, nxt+cur);
		DP(idx+1, open, nxt+cur);
		mem[idx][open][ncur]=true;
	}
	
	return;
	
}
 
int main(){
	string s;
	char c;
	while(getline(cin, s)){
		stringstream ss(s);
		memset(mem, 0, sizeof mem);
		memset(vis, 0, sizeof vis);
		// memset(num, 0, sizeof num);
		// memset(sign, 0, sizeof sign);
		n=0;
		ss>>num[n];
		while(ss>>c){
			sign[++n]=c=='-';
			ss>>num[n];
		}
		n++;
		DP(1,0,num[0]);
		int ans=0;
		for(int i=1;i<=MAX_N;i++)ans+=vis[i];
		printf("%d\n", ans);
		
	}
	return 0;
}