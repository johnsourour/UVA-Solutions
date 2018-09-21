#include <bits/stdc++.h>
using namespace std;
#define MAX 2147483647
int countDigits(int n){
	int tot=0;
	while(n){n/=10;tot++;}
	return tot;
}
vector<long int> nums;
void gen(){
	long int inc=1, acc=1, prev=1;
	
	nums.push_back(acc);
	while(nums.back()<MAX){
		inc++;
		acc+=countDigits(inc);
		nums.push_back(nums.back()+acc);
	
	}
}
int main(){
	int T,n;
	scanf("%d",&T);
	gen();
	while(T--){
	  scanf("%d",&n);
	  long int ind = lower_bound(nums.begin(), nums.end(),n) - nums.begin();
	  long int cur = nums[ind];
	  long int rem = nums[ind]-n;
	  long int actual_num = ind+1;
	 // cout<<cur<<" "<<rem<<" "<<ind+1<<endl;
	  long int dig = countDigits(actual_num);
	  while(rem>=dig){
	  //	cout<<actual_num<<" "<<rem<<endl;
	  	rem-=dig;
	  	actual_num--;
	  	dig = countDigits(actual_num);
	  //	cout<<dig<<endl;
	  }
	  //cout<<"ac: "<<actual_num<<endl;
	  long int ans=actual_num%10;
	  while(rem){
	  	rem--;
	  	actual_num/=10;
	  	ans=actual_num%10;
	  }
	  cout<<ans<<endl;
	}
}