#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
#define INF 1e9
#define MAX_BS (1<<16) - 1
#define MAX_N 20

int n;
double mem[MAX_BS];
double dist[MAX_N][MAX_N];
ii pos[MAX_N];

double DP(int cur){
	if(cur==(1<<(2*n))-1)return 0.0;
	if(mem[cur]>-0.5) 
	{
		int i;
		for(i=0;i<2*n;i++)if(!(cur & (1<<i)))break;
		double ans=INF;
		for(int j=i+1; j<2*n;j++){
			if(!(cur & (1<<j))){
				ans=min(ans, dist[i][j]+DP(cur | (1<<i) | (1<<j)));
			}
		}
		mem[cur]=ans;
	}
	return mem[cur];
}

int main(){
	int x, y, K=0;
	string tmp;
	while(scanf("%d", &n)!=EOF && n){
		for(int i=0;i<(1<<(2*16));i++)mem[i]=-1.0;
		for(int i=0;i<2*n;i++){
			cin>>tmp>>pos[i].first>>pos[i].second;
		}
		for(int i=0;i<2*n;i++)
			for(int j=i+1;j<2*n;j++)
				dist[i][j]=dist[j][i]=hypot(pos[i].first-pos[j].first,pos[i].second-pos[j].second);
		printf("Case %d: %.2lf\n",++K,DP(0));
		
	}

}