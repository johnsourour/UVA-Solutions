10452 - Marcus#include <bits/stdc++.h>
using namespace std;
#define MAX 10
int M,N, sx, sy, ex, ey;
set<char> st;
vector<int> order;
char grid[MAX][MAX];
int dc[3]={0,1,-1};
int dr[3]={-1,0,0};
string say[3]={"forth","right","left"};
bool can(int x, int y){
	if(x<0 || y<0 || x>=N || y>=M || !st.count(grid[x][y]) )return false;
	st.erase(grid[x][y]);
	return true;
}
void traverse(int x,int y){
	for(int i=0;i<3;i++)
	{
		int nx=x+dr[i],ny=dc[i]+y;
		if(can(nx,ny)){
			order.push_back(i);
			traverse(nx,ny);
			
			return;
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	string s = "IEHOVA#";
	while(T--){
		scanf("%d%d",&N,&M);
		for(char c:s)st.insert(c);
		order.clear();
		for(int i=0;i<N;i++)for(int j=0;j<M;j++){
			scanf(" %c",&grid[i][j]);
			if(grid[i][j]=='@')sx=i,sy=j;
			else if(grid[i][j]=='#')ex=i,ey=j;
		}
		traverse(sx,sy);
		cout<<say[order[0]];
		for(int i=1;i<order.size();i++)cout<<" "<<say[order[i]];
		cout<<endl;
		
	}
	return 0;
}