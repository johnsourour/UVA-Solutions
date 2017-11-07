#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int main()
{
	int n;
	char c[MAX];
	string s;
	unordered_map<string,int> mp;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s",&c[0],sizeof c);
		s=c;
		mp.clear();
		for(int i=0;i<s.length()-n+1;i++)
			mp[s.substr(i,n)]++;
			
		unordered_map<string,int>::iterator it;
		int mx=0;
		string ans;
		for(it=mp.begin();it!=mp.end();++it)
		{
			//cout<<it->first<<" "<<it->second<<endl;
			if(it->second>mx)
			{
				mx=it->second;
				ans=it->first;
			}
		}
		printf("%s\n",ans.c_str());
	}
}
