#include<bits/stdc++.h>
using namespace std;
int comp(string s1,string s2)
{
	if(s1.length()!=s2.length())return -1;
	int ans=0;
	for(int i=0;i<s1.length();i++)
	{
		if(s1.at(i)!=s2.at(i))ans++;
	}
	return ans;
}
vector<string> dict;
vector<bool> seen;
vector<vector<int> > adjList;
map<string,int> m;
int BFS(string s, string d)
{
	seen.clear();
	if(s.compare(d)==0)return 0;
	seen.resize(dict.size());
	queue<pair<string,int> > q;
	q.push(make_pair(s,0));
	seen[m[s]]=true;
	while(!q.empty())
	{
		pair<string,int> f=q.front();q.pop();
		for(int i:adjList[m[f.first]])
		{
			if(seen[i])continue;
			
			seen[i]=true;
			if(dict[i].compare(d)==0){return f.second+1;}
			q.push(make_pair(dict[i],f.second+1));
			
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	string s,w1,w2;
	getline(cin,s);
	getline(cin,s);
	while(T--)
	{
		m.clear();
		int i=0;
		dict.clear();
		getline(cin,s);
		while(s!="*")
		{
			dict.push_back(s);
			m.insert(make_pair(s,i));i++;
			getline(cin,s);
		}
		adjList.clear();
		adjList.resize(i);
		for(int k=0;k<i;k++)
		{
			for(int l=k+1;l<i;l++)
			{
				if(comp(dict[k],dict[l])==1)
				{
					adjList[k].push_back(l);
					adjList[l].push_back(k);
				}
			}
		}
		
		while(true)
		{
				getline(cin,s);	
				if(s.length()<1)break;
			w1=w2="";
			while(s.at(0)!=' ')
			{
				w1+=s.at(0);
				s.erase(0,1);
			}
			s.erase(0,1);
			while(s.length()>0)
			{
				w2+=s.at(0);
				s.erase(0,1);
			}
			printf("%s %s %d\n",w1.c_str(),w2.c_str(),BFS(w1,w2));
		
		
		}
			if(T)printf("\n");
		
	}
	return 0;
}
