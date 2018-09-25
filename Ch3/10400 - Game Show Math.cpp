#include<bits/stdc++.h>
using namespace std;
#define MAX 105
#define LIMIT 32000
typedef long long ll;
string sol;
string op[4]={"+","-","*","/"};
vector<int> nums;
int target, cur_res;
int mem[MAX][1+(LIMIT*2)];
bool can(int cur, int op, int next){
	ll res;
	bool flag;
	if(op==0)res=cur+next;
	else if(op==1)res=cur-next;
	else if(op==2)res=cur*next;
	else {
		cur_res=cur/next;
		return (cur%next)==0;
	}
	
	flag = (res<=LIMIT && res>=-LIMIT);
	if(flag)cur_res=res;
	return flag;
}
bool DP(int idx, int cur){
	if(idx>=nums.size() || (cur+LIMIT)<0) return 0;
	if(idx==nums.size()-1){
		if(cur==target){
			sol+=to_string(nums[idx])+"="+to_string(target);
			return 1;
		}
		else return 0;
	}
	if(mem[idx][cur+LIMIT]==-1){
		bool flag=false;
		
		sol+=to_string(nums[idx]);
		
		string old=sol;
		for(int i=0;i<4 && !flag;i++){
			sol+=op[i];
			
			if(can(cur, i, nums[idx+1])) {
				flag = DP(idx+1, cur_res);
			}
			if(!flag)sol=old;
		}	
		mem[idx][cur+LIMIT]=flag;
	}
	return mem[idx][cur+LIMIT];
}
int main()
{
	int t, p;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&p);
		nums.clear();
		nums.resize(p);
		sol="";
		for(int i=0;i<p;i++)scanf("%d",&nums[i]);
		memset(mem, -1, sizeof mem);
		scanf("%d",&target);
		if(DP(0,nums[0])){
			printf("%s\n", sol.c_str());	
		}
		else printf("NO EXPRESSION\n");
	}
}
