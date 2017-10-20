#include<bits/stdc++.h>
using namespace std;
	map<char,int> mp;
int main()
{
	int n,K=1;
	cin>>n;
	string s;
	while(n--)
	{	
		mp.clear();
		cin>>s;
		stack<char>st;
		mp[s.at(0)]++;
		st.push(s.at(0));
		mp[s.at(1)]++;
		st.push(s.at(1));
		for(int i=2;i<s.length();i++)
		{
			char c=s.at(i);
			if(c==st.top())st.pop();
			else
			{
				mp[c]++;
				mp[st.top()]++;
				st.push(c);	
			}
		}
		printf("Case %d\n",K++);
		for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			printf("%c = %d\n",it->first,it->second);	
		}
	}
}
