#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > spe, orig;
vector<bool> done;

int main()
{
	int c,s,K=0;
	double tot,avg,cur,res;
	while(scanf("%d%d",&c,&s)!=EOF){
		spe.clear();
		done.clear();
		orig.clear();
		spe.resize(2*c);
		done.resize(2*c);
		orig.resize(2*c);
		tot=0.0;
		for(int i=0;i<2*c;i++){
			int tmp=0;
			if(i<s){
				scanf("%d",&tmp);
			}
			orig[i].first=tmp;
			spe[i].first=tmp;
			spe[i].second = i;
			tot+=tmp;
		}
		sort(spe.begin(),spe.end());
		avg=tot/((double)c);
		res=0;
		printf("Set #%d\n",++K);
		vector<vector<int> > out(c);
		for(int i=0;i<c;i++){
			int f=spe[i].first,s=spe[(2*c)-1-i].first;
			int ind_f=spe[i].second,ind_s=spe[(2*c)-1-i].second;
			if(ind_f>ind_s){
				swap(ind_f,ind_s);
				swap(f,s);
			}
			cur=f+s;
			out[i].push_back(ind_f);
			orig[ind_f].second=i;
			out[i].push_back(ind_s);
			orig[ind_s].second=i;
			res+=abs(cur-avg);
		}
		int st=0;
		for(auto x:orig){
			if(!done[x.second]){
				printf(" %d:",st++);
				for(int xx:out[x.second]){
					if(orig[xx].first)printf(" %d",orig[xx].first);
				}
				printf("\n");
				done[x.second]=true;	
			}
		}
		printf("IMBALANCE = %.5lf\n\n",res);
	
	}
}
