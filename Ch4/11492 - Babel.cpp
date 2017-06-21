#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef vector<int> vi;
typedef pair<string,int> si;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

	string S,E,x1,x2,w;
vector<string> lang;
vector<string> words;
map<string,int> ml;
map<string,int> mw;
vector<set<int> > common;
vector<vector<iii> > adjList;
int dijkstra(int s, int e)
{
	vi dist(adjList.size(), INF); dist[s] = 0; 
	priority_queue< iii, vector<iii>> pq; pq.push(iii(-1,ii(0, s)));
	while (!pq.empty())
	{ 
		iii front = pq.top(); pq.pop(); 
		int t=front.first, d = front.second.second, u = front.second.first;
		if (d > dist[u]) continue;
		for (iii v:adjList[u]) 
		{
			if(t==v.first)continue;
			if (dist[u] + v.second.second < dist[v.second.first]) 
			{
				dist[v.second.first] = dist[u] + v.second.second;
				pq.push(iii(v.first,ii(v.second.first,dist[v.second.first])));
			} 
		}
	}
	return dist[e];
}
int main()
{
	int M,k,wk;
	scanf("%d",&M);
	vector<iii> start;
	while(M)
	{
		wk=k=0;
		start.clear();
		common.clear();
		mw.clear();
		words.clear();
		ml.clear();
		lang.clear();
		cin>>S>>E;
		if(ml.find(S)==ml.end()){ml.insert(si(S,k++));lang.push_back(S);}
		if(ml.find(E)==ml.end()){ml.insert(si(E,k++));lang.push_back(E);}
		while(M--)
		{
			cin>>x1>>x2>>w;
			if(ml.find(x1)==ml.end()){ml.insert(si(x1,k++));lang.push_back(x1);}
			if(ml.find(x2)==ml.end()){ml.insert(si(x2,k++));lang.push_back(x2);}
			
			if(mw.find(w)==mw.end()){
				mw.insert(si(w,wk++));
				words.push_back(w);
				set<int> tmp;
				tmp.insert(ml[x1]);
				tmp.insert(ml[x2]);
				common.push_back(tmp);
			}
			else
			{
				common[mw[w]].insert(ml[x1]);
				common[mw[w]].insert(ml[x2]);
			}
			if(x1.compare(S)==0 || x2.compare(S)==0)start.push_back(iii(ml[S],ii(mw[w]+1,w.size())));
			
		}
		adjList.clear();
		adjList.resize(wk+1);
		adjList[0]=start;
		for(int i=0;i<wk;i++)
		{
			for(int j=i+1;j<wk;j++)
			{
				
				int ln;
				bool flag=false;
				string s1=words[i],s2=words[j];
				if(s1.at(0)==s2.at(0))continue;
				if(common[j].size()<common[i].size()){
					for(int jt:common[j])
					{
					
						if(common[i].count(jt)){
							ln=jt;
							flag=true;
							break;
						}
					}
				}
				else
				{
					for(int it:common[i])
					{
						if(common[j].count(it)){
						ln=it;
							flag=true;
							break;
						}
					}
				}
				if(flag)
				{
					adjList[i+1].push_back(iii(ln,ii(j+1,words[j].length())));
					adjList[j+1].push_back(iii(ln,ii(i+1,words[i].length())));
				}
			}
		}
		for(int i=1;i<adjList.size();i++)
		{
			if(common[i-1].count(ml[E]))adjList[i].push_back(iii(ml[E],ii(wk+1,0)));

		}
		adjList.push_back(vector<iii>());
		int ans=dijkstra(0,wk+1);
		
		if(ans<INF)cout<<ans<<endl;
		else cout<<"impossivel\n";
		scanf("%d",&M);
	}
	return 0;
}
