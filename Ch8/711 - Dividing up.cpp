#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool can;
ll marbles[6];
bool solve(int i, ll rem, int depth){
	
	if(depth>marbles[i] || i==6)return false;
	if(rem==0)return true;
	return solve(i+1, rem,0) || solve(i, rem-i-1,depth+1);
}
int main(){
	int K=0;
	while(1){
		ll tot=0;
		for(int i=0;i<6;i++){
			cin>>marbles[i];
			tot+=(marbles[i]*(i+1));
		}
		if(tot==0)break;
		printf("Collection #%d:\n",++K);
		if(tot%2==0)
		for(ll i=0;i<6;i++){
			if(marbles[i]>13){
				int rem = marbles[i]&1;
				tot-=(marbles[i]-12-rem)*(i+1);
				marbles[i]=rem+12;
			}
			
		}
		ll target = tot/2;
		if(tot%2==0 && solve(0,target,0)){
			printf("Can be divided.\n\n");
		}
		else{
			printf("Can't be divided.\n\n");
		}
	}
	return 0;
	
}