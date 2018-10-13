#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
typedef pair<string, int> si;
typedef pair<int, int> ii;
si cities[MAX][2];
ii mem[MAX][MAX];
int l,r;

ii DP(int i, int j){
	if(i>=l || j>=r)return ii(0,0);
	if(mem[i][j]==ii(-1,-1)){
		ii a = DP(i,j+1), b = DP(i+1, j);
		ii mx;
		if(a.second==b.second)mx=b.first>a.first? a:b;
		else mx=a.second>b.second?a:b;
		
		if(cities[j][1].first.compare(cities[i][0].first)==0){
			ii ret = DP(i+1, j+1);
			ret.first++;
			ret.second+=cities[j][1].second+cities[i][0].second;
			if(ret.second==mx.second){
				mx.first=min(mx.first, ret.first);
			}
			else if(ret.second>mx.second){
				mx.first=ret.first;
				mx.second=ret.second;
			}
		}	
		
		mem[i][j]=mx;
	}
	return mem[i][j];
}

int main(){
	int TC, tmp;
	string s;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d",&l);
		memset(mem, -1, sizeof mem);
		for(int i=0;i<l;i++){
			cin>>s>>s>>tmp;
			cities[i][0]=si(s,tmp);
		}
		scanf("%d",&r);
		for(int i=0;i<r;i++){
			cin>>s>>s>>tmp;
			cities[i][1]=si(s,tmp);
		}
		ii ans = DP(0,0);
		cout<<ans.second<<" "<<ans.first<<endl;
	}
	
	return 0;
}