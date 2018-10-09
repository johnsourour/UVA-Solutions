#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool can;
ll target;
ll marbles[6];
bool solve(int i, ll rem, int depth){
	if(rem==0)return true;
	if(i==6 || depth>marbles[i])return 0;
	return solve(i+1, rem-i+1,0) || solve(i+1, rem,0) || solve(i, rem-i+1,depth+1);
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
		if(K)printf("\n");
		printf("Collection #%d:\n",++K);
		
		for(int i=0;i<6;i++){
			if(marbles[i]>12){
				int rem = marbles[i]%2;
				tot-=(marbles[i]-12-rem)*(i+1);
				marbles[i]=rem+12;
			}
			
		}
		target = tot/2;
		if(tot%2==0 && solve(0,target,0)){
			printf("Can be divided.\n");
		}
		else{
			printf("Can't be divided.\n");
		}
	}
	return 0;
	
}