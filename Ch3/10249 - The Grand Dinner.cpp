#include<bits/stdc++.h>
using namespace std;
struct comp{
	bool operator()(const pair<int, int>&a,const pair<int,int> &b){
		return a.first>b.first;
	}	
};
struct comp2{
	bool operator()(const pair<pair<int,int>, set<int> >&a,const pair<pair<int,int>, set<int> > &b){
		return a.first.first>b.first.first;
	}	
};
int main()
{
	int N,M,tmp;
	while(scanf("%d%d",&M,&N)!=EOF && (M||N)){
		vector< pair<pair<int,int>,set<int> > > tables(N);
		vector<pair<int,int> > teams(M);
		for(int i=0;i<M;i++){
			scanf("%d",&tmp);
			teams[i].second = i+1;
			teams[i].first = tmp;
		}
		for(int i=0;i<N;i++){
			scanf("%d",&tmp);
			tables.push_back(make_pair(make_pair(tmp,i+1), set<int>()));
		}
		bool valid=true;
		sort(teams.begin(),teams.end(), comp());
		
		vector<vector<int> > ans(M);
		for(int i=0;i<M && valid;i++){
			sort(tables.begin(),tables.end(), comp2());
			int rem = teams[i].first, num = teams[i].second;
			//cout<<num<<" "<<rem<<endl;
			for(int k=0;k<N && rem>0;k++){
			//	cout<<tables[k].first<<" ";
				if(tables[k].first.first==0 || tables[k].second.count(num)>0)continue;
				rem--;
				tables[k].first.first--;
				ans[num-1].push_back(tables[k].first.second);
				tables[k].second.insert(num);
			}
		//	cout<<endl;
			valid = rem==0;
		}
		printf("%d\n",valid);
		if(valid){
			for(vector<int>v :ans){
				bool ff=0;
				for(int x: v){
					if(ff)printf(" ");
					ff=1;
					printf("%d",x);
				}
				printf("\n");
			}	
		}
	}
}
