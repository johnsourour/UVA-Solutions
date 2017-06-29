#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define MAX_I 50005
#define MAX_V 405
#define INF 1e9
map<int,int> mt;
int res[MAX_V][MAX_V], f, s, t, n, m;
set<int> sint;
vector<ii> intervals;
vector<iii> monkeys;
ll total, mf;
vi p, mx;
void augment(int v, int minEdge)
{
	if (v == s) { f = minEdge; return; }
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}
void EdmondKarps()
{
	mf = 0;
	while (1)
	{
		f = 0;
		vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
		p.assign(MAX_V, -1);
		while (!q.empty())
		{
			int u = q.front(); q.pop();
			if (u == t) break;
			for (int v = 0; v < MAX_V; v++)
			if (res[u][v] > 0 && dist[v] == INF){
				dist[v] = dist[u] + 1; q.push(v); p[v] = u;
			}
		}
		augment(t, INF);
		if (f == 0) break;
		mf += f;
	}
}
void init()
{
	memset(res, 0, sizeof res);
	sint.clear();
	intervals.clear();
	monkeys.clear();
	total = 0;

	int w, x, y;
	for (int i = 0; i<n; i++)
	{
		scanf("%d%d%d", &w, &x, &y);
		vector<int> tmp;
		tmp.push_back(i + 301);
		res[s][i + 301] = w;
		total += w;
		monkeys.push_back(iii(w, ii(x, y)));
		sint.insert(x);
		sint.insert(y);

	}
	set<int>::iterator it1, it2;
	it2 = it1 = sint.begin(); ++it2;
	while (it2 != sint.end())
	{
		intervals.push_back(ii(*it1, *it2));
		++it1; ++it2;
	}
	for (int i = 0; i<intervals.size(); i++)res[i][t] = m*(intervals[i].second - intervals[i].first);

	for (int i = 0; i<n; i++)
	{
		res[s][i + 301] = monkeys[i].first;
		int xx = monkeys[i].second.first, yy = monkeys[i].second.second;
		for (int j = 0; j<intervals.size(); j++)
		{

			int intx = intervals[j].first, inty = intervals[j].second;
			if (xx <= intx && yy >= inty)res[i + 301][j] = inty - intx;
		}

	}

}
void output()
{
	vector<vector<ii> >ans(n);
	vector<int>counter;
	int st;
	for(int i=0;i<intervals.size();i++)counter.push_back(intervals[i].first);
	for (int i = 0; i<intervals.size(); i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (res[i][j + 301]>0)
			{
				st=counter[i];
				for(int k=0;k<res[i][j + 301];k++)
				{
				
        		 if(counter[i]==intervals[i].second){
                	if(st!=intervals[i].second)ans[j].push_back(ii(st,intervals[i].second));
                	st=counter[i]=intervals[i].first;
            		}
            		 ++counter[i];
    		 	}
        		if(st!=counter[i])ans[j].push_back(ii(st,counter[i]));	
			}
		}
				
	}
		/*sort(tmp.begin(), tmp.end());
		vector<ii> tmp2;
		for (int j = 0; j<tmp.size(); j++)
		{
			if (j<tmp.size() - 1 && tmp[j].second == tmp[j + 1].first)tmp[j + 1].first = tmp[j].first;
			else tmp2.push_back(tmp[j]);
		}*/
	
	for (int i=0;i<n;i++)
	{
		sort(ans[i].begin(),ans[i].end());
	
		vector<ii> tmp2;
		for(int j=0;j<ans[i].size();j++)
		{
			if(j<ans[i].size()-1 && ans[i][j].second==ans[i][j+1].first)ans[i][j+1].first=ans[i][j].first;
			else tmp2.push_back(ans[i][j]);
		}
		if(tmp2.size())ans.push_back(tmp2);
		ans[i]=tmp2;
		printf("%d", ans[i].size());
		for (ii a : ans[i])
		{
			printf(" (%d,%d)", a.first, a.second);
		}
		printf("\n");
	}
}
int main()
{
	int K = 1;
	s = MAX_V - 2; t = MAX_V - 1;
	scanf("%d", &n);
	while (n)
	{
		scanf("%d", &m);
		init();
		EdmondKarps();
		printf("Case %d: ", K++);

		if (total == mf)
		{

			printf("Yes\n");
			output();
		}
		else printf("No\n");
		scanf("%d", &n);
	}
	return 0;
}
