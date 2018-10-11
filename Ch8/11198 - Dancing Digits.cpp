#include <bits/stdc++.h>
using namespace std;

#define GOAL "12345678"
#define is pair<int, state>

struct state{
	string num;
	bitset<8> female;
	state(string n, bitset<8> bs){
		female=bs;
		num=n;
	}
};
unordered_map<string,bool> vis;
bool operator<(const is &a, const is &b){
	return a.first>b.first;
}

bool isPrime(int n1, int n2){
	int n=n1+n2;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}
int BFS(state start){
	 priority_queue<is> pq;
	 pq.push(is(0, start));
	 vis[start.num]=1;
	 while(!pq.empty()){
	 	state front=pq.top().second; int depth = pq.top().first; pq.pop();
	 	string num=front.num; bitset<8> bs=front.female;
	 	
	 	if(num.compare(GOAL)==0)
	 		return depth;
	 	
	 	for(int i=0;i<num.length();i++){
	 		for(int j = 0;j<num.length();j++){
	 			if(isPrime(num[j]-'0', num[i]-'0') && bs[j]!=bs[i]){
						string nnum1 = num,  sbs1 = bs.to_string(), nnum2 = num, sbs2 = bs.to_string();
						
						reverse(sbs1.begin(), sbs1.end());
						reverse(sbs2.begin(), sbs2.end());
						
						nnum1.insert(nnum1.begin()+j+1,nnum1[i]); sbs1.insert(sbs1.begin()+j+1,sbs1[i]);
		 				nnum2.insert(nnum2.begin()+j,nnum2[i]);	sbs2.insert(sbs2.begin()+j,sbs2[i]);
		 				
			 			if(i<j){
		 					nnum1.erase(i,1); sbs1.erase(i,1);
		 					nnum2.erase(i,1); sbs2.erase(i,1);
		 				}
		 				else {
	 						nnum1.erase(i+1,1); sbs1.erase(i+1,1);
	 						nnum2.erase(i+1,1);	sbs2.erase(i+1,1);
		 				}
		 				reverse(sbs1.begin(), sbs1.end());
		 				reverse(sbs2.begin(), sbs2.end());
		 				
		 				bitset<8> nbs1(sbs1), nbs2(sbs2);
						
						state nxt1(nnum1, nbs1), nxt2(nnum2, nbs2);
						
						if(vis.find(nnum1)==vis.end()){
			 				vis[nnum1]=1;
			 				pq.push(make_pair(depth+1, nxt1));
			 			}
			 			
			 			if(vis.find(nnum2)==vis.end()){
			 				vis[nnum2]=1;
			 				pq.push(make_pair(depth+1, nxt2));
			 			}
				
	 				
	 			}
	 		}
	 	}
	 	
	 }
	 return -1;
}

int main(){
	string n;
	int K=0, tmp;
	bitset<8> bs;
	while(scanf("%d", &tmp)!=EOF && tmp){
		bs.reset();
		vis.clear();
		n="";
		if(tmp<0){
			bs[0]=1;
		}
		tmp = abs(tmp);
		n+=to_string(tmp);
		for(int i=1;i<8;i++){
			cin>>tmp;
			if(tmp<0)bs[i]=1;
			tmp=abs(tmp);
			n+=to_string(tmp);
			
		}
		
		int ans=BFS(state(n,bs));
		printf("Case %d: %d\n",++K, ans);
	}
	return 0;
	
}