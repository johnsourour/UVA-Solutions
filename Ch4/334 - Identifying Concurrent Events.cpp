#include<bits/stdc++.h>
using namespace std;
typedef pair<string,int> si;
typedef pair<int,int> ii;
bool adjMat[201][201];
vector<string> sys;
map<string,int> m;
int main()
{
	int n,cnt,t,msg,K=1;
	string s;
	vector<vector<int> > e;
	scanf("%d",&n);
	while(n)
	{
		cnt=0;
		e.clear();
		m.clear();
		sys.clear();
		for(int i=0;i<n;i++)
		{
			cin>>t;
			vector<int> tmp;
			while(t--)
			{
				cin>>s;
				if(m.find(s)==m.end())
				{
					m.insert(si(s,cnt++));
					sys.push_back(s);
				}
				tmp.push_back(m[s]);
			}
			e.push_back(tmp);
		}
		cin>>msg;
		while(msg--)
		{
			vector<int> tmp;
			cin>>s;
			tmp.push_back(m[s]);
			cin>>s;
			tmp.push_back(m[s]);
			e.push_back(tmp);
		}
		for(int i=0;i<cnt;i++)
				for(int j=0;j<cnt;j++)
				{
					adjMat[i][j]=0;
				}
		for(vector<int> vi:e)
		{
			for(int i=0;i<vi.size();i++)
				for(int j=i+1;j<vi.size();j++)
				{
					adjMat[vi[j]][vi[i]]=1;
				}
		}
		int conc=0;
		ii f,s;
		for(int k=0;k<cnt;k++)
			for(int i=0;i<cnt;i++)
				for(int j=0;j<cnt;j++)
				{
					adjMat[i][j]=adjMat[i][j] || (adjMat[i][k] && adjMat[k][j]);
				}
				
		for(int i=0;i<cnt;i++)
				for(int j=i+1;j<cnt;j++)
				{
					if(!adjMat[i][j] && !adjMat[j][i])
					{
						conc++;
						s=f;
						f=ii(i,j);
					}
				}		
		if(conc>1)
		printf("Case %d, %d concurrent events:\n(%s,%s) (%s,%s) \n",K++,conc,sys[f.first].c_str(),sys[f.second].c_str(),sys[s.first].c_str(),sys[s.second].c_str());
		else if(conc==1)
			printf("Case %d, %d concurrent events:\n(%s,%s) \n",K++,conc,sys[f.first].c_str(),sys[f.second].c_str());
		else
			printf("Case %d, no concurrent events.\n",K++);
		
		scanf("%d",&n);
	}
	
}
