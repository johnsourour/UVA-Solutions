#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
typedef pair<int,int> ii;
int main()
{
	int n;
	char c[MAX];
	string s1,s2;
	unordered_map<char,ii> mp;
	while(getline(cin,s1))
	{
		
		getline(cin,s2);
		mp.clear();
		for(char cc:s1)mp[cc].first++;
		for(char cc:s2)mp[cc].second++;
		unordered_map<char,ii>::iterator it;
		
		string ans="";
		for(it=mp.begin();it!=mp.end();++it)
		{
			int mx=min(it->second.second,it->second.first);
			for(int i=0;i<mx;i++)ans+=it->first;
		}
		sort(ans.begin(),ans.end());
		printf("%s\n",ans.c_str());
	}
}
