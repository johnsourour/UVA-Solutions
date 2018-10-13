#include<bits/stdc++.h>
using namespace std;

typedef pair<string,int> si;
string t;
int n;
map<string,int> dist_s, dist_t;

vector<string> getNext(string s){
	vector<string> ans;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			string cur=s;
			string sub=s.substr(i,j-i+1);
			cur.erase(i,j-i+1);
			for(int k=0;k<n-(j-i);k++){
				string tmp="";
				int nxt=0;
				for(int kk=0;kk<n-(j-i);kk++){
					if(kk==k)tmp+=sub;
					else tmp+=cur[nxt++];
				}
				if(tmp.compare(s)!=0)ans.push_back(tmp);
			}
		}
	}
	return ans;
}
int BFS(string u, int mx, bool finish){
	queue<si> q;
	q.push(si(u, 0));
	if(!finish && u.compare(t)==0)return 0;
	while(!q.empty()){
		si front = q.front(); q.pop();
		string s = front.first;
		int depth = front.second;
		
		if(depth<mx){
			vector<string> nxt = getNext(s);
			for(string ss:nxt){
				if(finish){
					if(dist_s.find(ss)!=dist_s.end()) return depth+1+dist_s[ss];
					if(dist_t.find(ss)!=dist_t.end())continue;
					dist_t[ss]=depth+1;
				}
				else{
					if(ss.compare(t)==0) return depth+1;
					if(dist_s.find(ss)!=dist_s.end())continue;
					dist_s[ss]=depth+1;
				}
				q.push(si(ss,depth+1));
			}
		}
	}
	return -1;
}

int main(){
	int tmp,ans, K=0;
	string start;
	while(scanf("%d", &n)!=EOF && n){
	
		dist_s.clear();
		dist_t.clear();
		start="";
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			start+=to_string(tmp);
		}
		t=start;
		sort(t.begin(), t.end());
	//	cout<<start<<" "<<t<<endl;
		ans = BFS(start, 2, 0);
		if(ans==-1){
			ans = BFS(t, 2, 1);
		}
		if(ans==-1)ans=5;
		printf("Case %d: %d\n", ++K, ans);
		
	}
	return 0;
}