#include <bits/stdc++.h>
using namespace std;

#define MAX 65
#define INF 1e9
typedef long long ll;

ll adjMat[MAX], done;
int n,m,mx,ans;

void solve(int i, ll curSet, int cnt){
	if(curSet==done){
		mx=max(cnt, mx);
		ans++;
		return;
	}
	for(int k=i;k<n;k++){
		if(!(curSet & (1<<k))){
			solve(k+1, curSet | adjMat[k], cnt+1);
		}
	}
}
int main(){
	int TC;
	cin>>TC;
	while(TC--){
		cin>>n>>m;
		mx=-INF;
		ans=0;
		for(int i=0;i<n;i++){
			adjMat[i]=(1<<i);
		}
		done=(1<<n)-1;
		int f,t;
		for(int i=0;i<m;i++){
			cin>>f>>t;
			adjMat[f]|=(1<<t);
			adjMat[t]|=(1<<f);
		}
		solve(0,0,0);
		printf("%d\n%d\n",ans,mx);
	}
	return 0;
	
}