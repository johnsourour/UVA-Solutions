#include<bits/stdc++.h>
using namespace std;
#define MAX 10005

int main()
{
	int n,lis,lis2;
	vector<int> nums, LIS, LDS ,L, U;
	while(scanf("%d",&n)!=EOF){
		lis=lis2=0;
		L.clear();
		L.resize(n);
		nums.clear();
		nums.resize(n);
		U.clear();
		U.resize(n);
		LIS.clear();
		LIS.resize(n);
		LDS.clear();
		LDS.resize(n);
		for(int i=0;i<n;i++){
			scanf("%d",&nums[i]);
		}
		
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int pos = lower_bound(L.begin(), L.begin() + lis, nums[i]) - L.begin();
			int pos2 = lower_bound(U.begin(), U.begin() + lis2, nums[n-i-1]) - U.begin();
			
			U[pos2] = nums[n-i-1];
			L[pos] = nums[i];
			if (pos + 1 > lis) {
				lis = pos + 1;
				
			}
			if (pos2 + 1 > lis2) {
				lis2 = pos2 + 1;
				
			}
			
			LIS[i]=pos + 1;
			LDS[n-1-i]=pos2 + 1;
			
		}
		for(int i=0;i<n;i++){
			ans=max(ans, 2*min(LDS[i],LIS[i])-1);
		}
		printf("%d\n",ans);
	}

	
	
	
}
