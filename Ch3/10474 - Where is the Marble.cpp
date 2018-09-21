#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,Q,K=0;
	vector<int> mar;
	while(scanf("%d%d",&N,&Q)!=EOF && (N || Q)){
		mar.clear();
		mar.resize(N);
		
		for(int i=0;i<N;i++)scanf("%d",&mar[i]);
		sort(mar.begin(),mar.end());
		printf("CASE# %d:\n",++K);
		while(Q--){
			int tmp;
			scanf("%d",&tmp);
			int ind = lower_bound(mar.begin(),mar.end(),tmp) - mar.begin();
			if(ind<mar.size() && mar[ind]==tmp)
				printf("%d found at %d\n",tmp,ind+1);
			else printf("%d not found\n",tmp);
		}
	}
	
}