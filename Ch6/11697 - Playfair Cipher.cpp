#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
map<char,ii> mp;
set<char> st;
char table[5][5];
void mapKeys()
{
	for(int i=0;i<5;i++)
	for(int j=0;j<5;j++)
		mp[table[i][j]]=ii(i,j);	
}
void init()
{
	st.clear();
	for(int i=0;i<26;i++)if((char)('A'+i)!='Q')st.insert((char)('A'+i));
}
void remove(string &s)
{
	while(s.length()>0 && s.at(0)==' ')s.erase(0,1);

}
void add(char c1, char c2, string &s)
{
	c1=toupper(c1);
	c2=toupper(c2);
	ii p1=mp[c1],p2=mp[c2];
	if(p1.first==p2.first)
	{
		p1.second=(p1.second+1)%5;
		p2.second=(p2.second+1)%5;
	}
	else if(p1.second==p2.second)
	{
		p1.first=(p1.first+1)%5;
		p2.first=(p2.first+1)%5;	
	}
	else
	{
		swap(p1.second,p2.second);
	}
	s+=table[p1.first][p1.second];s+=table[p2.first][p2.second];

}
string dec(string s)
{
	bool flag=false;
	string out="";
	char c1,c2;
	while(s.length()>0)
	{
		
		remove(s);
		c1=s.at(0);s.erase(0,1);
		remove(s);
		if(s.length()>0){
			c2=s.at(0);s.erase(0,1);
		}
		else c2='X';
		if(c1==c2){
			c2='X';
			s+=c1;
			
		}
		add(c1,c2,out);
		
		
	}
	return out;
}
int main()
{
	int T;
	string in,key;
	cin>>T;
	getline(cin,key);
	while(T--)
	{
		getline(cin,key);
		getline(cin,in);
		init();
		int i,j;
		i=j=0;
		for(char c:key)
		{
			if(c==' ')continue;
			c=toupper(c);
			if(st.count(c))
			{
				st.erase(c);
				table[i][j]=c;
				j++;
				if(j==5){j=0;i++;}
			}
		}
		for(set<char>::iterator it=st.begin();it!=st.end();++it)
		{
			table[i][j]=(*it);
			j++;
			if(j==5){j=0;i++;}
		}
		mapKeys();
		string ans=dec(in);
		cout<<ans<<endl;
	}
}
