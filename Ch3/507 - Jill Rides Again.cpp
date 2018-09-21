#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t;
	scanf("%d",&t);
	int K=0;
	vector<int> routes;
	while(t--){
		scanf("%d",&n);
		routes.clear();
		n--;
		routes.resize(n);
		
		int mx=-1e9,cur=0,st=0,mxst=0,mxend=0;
		for(int i=0;i<n;i++){
			scanf("%d",&routes[i]);
			
				cur+=routes[i];
		//	cout<<mxst<<" "<<mxend<<" "<<mx<<" "<<cur<<" "<<st<<" "<<i<<endl;
			if(routes[i]>mx){
				mx=routes[i];
				mxst=mxend=i;
			}
			if(cur>mx || (cur==mx && (mxend-mxst < i-st))){
				mx=cur;
				mxend=i;
				mxst=st;
			}
			else if(cur<0){
				st=i+1;
				cur=0;
			}
		}
		if(mx>0){
			printf("The nicest part of route %d is between stops %d and %d\n",++K,mxst+1,mxend+2);
		}
		else{
			printf("Route %d has no nice parts\n",++K);	
		}
		
	}
	
	
}
