#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getMin(vector<ll> nums, vector<bool> ops){
	for(int i=0;i<ops.size();i++){
		if(ops[i]){
			nums[i]*=nums[i+1];
			nums.erase(nums.begin()+i+1);
			ops.erase(ops.begin()+i);
			i--;
		}
	}
	ll res=0;
	for(ll i:nums)res+=i;
	return res;
}
ll getMax(vector<ll> nums, vector<bool> ops){
	for(int i=0;i<ops.size();i++){
		if(!ops[i]){
			nums[i]+=nums[i+1];
			nums.erase(nums.begin()+i+1);
			ops.erase(ops.begin()+i);
			i--;
		}
	}
	ll res=1;
	for(ll i:nums)res*=i;
	return res;	
}
int main()
{
	char c[40];
	string s;
	vector<ll> nums;
	vector<bool> ops;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",&c[0]);
		s=c;
		nums.clear();
		ops.clear();
		string prev=s.substr(0,1);
		for(int i=1;i<s.length();i++){
			if(!isdigit(s[i])){
				nums.push_back(stoi(prev));
				prev="";
				ops.push_back(s[i]=='*');
			}
			else{
				prev+=s[i];
			}
		}
		nums.push_back(stoi(prev));
		ll mn = getMin(nums,ops);
		ll mx = getMax(nums,ops);
		printf("The maximum and minimum are %lld and %lld.\n",mx,mn);
		
	}
}
