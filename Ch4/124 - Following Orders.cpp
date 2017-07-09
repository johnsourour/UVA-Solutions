#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > adjList;
vector<bool> seen;
bool found;
int n;
vector<int>cur;
vector<char> letters;
void backtrack(int i)
{
	if(cur.size()==n){
		for(int p=0;p<n-1;p++)printf("%c",letters[cur[p]]);
		printf("%c\n",letters[cur[n-1]]);
		found=true;
		return;
	}
	bool flag=true;
	for(int x:adjList[i])
	{
		flag=false;
		for(int k:cur)
		{
			if(k==x){flag=true;break;}
		}
		if(!flag)break;
	}
	if(flag)
	for(int k=0;k<n;k++)
	{
		if(!seen[k])
		{
			seen[k]=true;
			cur.push_back(k);
			backtrack(k);
			cur.pop_back();
			seen[k]=false;
		}
	}
	
}
int main()
{
	int T=0;
	map<char,int> m;
	char con[180],var[40];
	string C,V;
	scanf("%d",&T);
		
	while(getline(cin,V))
	{
		if(T)printf("\n");
		
		T=1;
		found=false;
		m.clear();
		letters.clear();
		seen.clear();
		cur.clear();
		getline(cin,C);
		int i=0;
		while(V.length()>0)
		{
			i++;
			letters.push_back(V.at(0));
			V.erase(0,1);
			if(V.length()>0)V.erase(0,1);
		}
		sort(letters.begin(),letters.end());
		n=i;
		i=0;
		for(char c:letters)m.insert(make_pair(c,i++));
		adjList.clear();
		adjList.resize(n);
		seen.resize(n);
		while(C.length()>0)
		{
			adjList[m[C.at(2)]].push_back(m[C.at(0)]);
			C.erase(0,3);
			if(C.length()>0)C.erase(0,1);
		}
		for(int k=0;k<n;k++)
		{
			seen[k]=true;
			cur.push_back(k);
			backtrack(k);
			cur.pop_back();
			seen[k]=false;
		}
	
		
	}
	
	return 0;	
}
