#include<bits/stdc++.h>
using namespace std;

#define MAX_B 12
#define MAX_S (1<<MAX_B)-1
#define MAX_N 130
#define INF 1e9

int n,m;
int mem[MAX_S][MAX_S];
int objects[MAX_N];


int DP(int q, int r){
//	cout<<bitset<11>(q)<<" "<<bitset<11>(r)<<endl;
	if(mem[q][r]==-1){
		int rem = 0;
		for(int i=0;i<n;i++)
			if((objects[i]&q)==r)
				rem++;
				
		if(rem<2) mem[q][r]=0;
		else{
			int ans = INF;
			for(int i=0;i<m;i++){
				int cur = (1<<i);
				if(!(q & cur))
					ans = min(ans, 1+max(DP(q | cur, r), DP(q | cur, r | cur)));
			}
			mem[q][r]=ans;
		}
	}
	return mem[q][r];
}

int main(){
	int start;
	string s;
	while(scanf("%d%d", &m, &n)!=EOF && n && m){
	
		start = 0;
		memset(mem, -1, sizeof mem);
	
		for(int i=0;i<n;i++)
		{
			cin>>s;
			objects[i]=(bitset<MAX_B>(s)).to_ulong();
			start|=objects[i];
		}
		
		printf("%d\n", DP(0,0));
	}
	return 0;
	
}