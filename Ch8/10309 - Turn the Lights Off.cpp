#include <bits/stdc++.h>
using namespace std;
#define MAX 10
#define INF 1e9
int grid[MAX];
int dr[5]={0,-1,1,0,0};
int dc[5]={0,0,0,-1,1};
int mn;

bool done(){
	for(int i=0;i<MAX;i++)if(grid[i])return false;
	return true;
}

void change(int i, int bit){
	if(i<0 || i>=MAX || bit<0 || bit>=MAX)return;
	grid[i]=grid[i]^(1<<bit);
}

void flip(int i, int bit){
	for(int k=0;k<5;k++)
		change(i+dr[k],bit+dc[k]);
}

void solve(int pos, int bit, int cur){
	if(bit==MAX){
		bit=0;
		pos++;
	}
	if(cur>=mn)return;
	if(pos==MAX){
		if(done()){
			mn=min(mn, cur);
		}
		return;
	}
	else if(pos>0 && (grid[pos-1] & (1<<bit))){
		flip(pos,bit);
		solve(pos,bit+1,cur+1);
		flip(pos,bit);
	}
	else if(pos>0){
		solve(pos,bit+1,cur);
	}
	else {
		flip(pos,bit);
		solve(pos,bit+1,cur+1);
		flip(pos,bit);
		solve(pos,bit+1,cur);
	}
	return;
	
	
}
int main() {
	string s, tmp;
	while(cin>>s && s!="end"){
		memset(grid, 0, sizeof grid);
		mn=INF;
		for(int i=0;i<MAX;i++){
			cin>>tmp;
			for(int j=0;j<MAX;j++){
				int on = tmp[MAX-1-j]=='O';
				grid[i]|=(on<<j);
			}
		}
		solve(0,0,0);
		cout<<s<<" "<<mn<<endl;
	}
	return 0;
}