#include<bits/stdc++.h>
using namespace std;
set<string> dict;
string msg;
int dec(int k, string &out)
{
	out="";
	for(int i=0;i<msg.length();i++)
	{
		char c=msg.at(i);
		int cur=(c==' ')?0:c-'A'+1;
		int nxt=(cur+k)%27;
		if(nxt==0)out+=' ';
		else out+='@'+nxt;
	}
	string tmp=out,cur;
	int ans=0;
	istringstream iss(tmp);
	while(iss>>cur)
	{
		if(dict.count(cur))ans++;
	}
	return ans;
}
int main()
{
	
	string s;
	cin>>s;
	while(s!="#")
	{
		dict.insert(s);
		cin>>s;
	}
	string ans,tmp;
	int mx=0,kk;
	getline(cin,msg);
	getline(cin,msg);
	
//	cout<<msg<<endl;
	for(int k=1;k<27;k++)
	{
		int cur=dec(k,tmp);
//		cout<<tmp<<endl;
		if(cur>mx)
		{
			kk=k;
			mx=cur;
			ans=tmp;
		}
	}
	istringstream iss(ans);
	string cur="",nxt;
	while(iss>>nxt)
	{
		
		if(cur.length()+nxt.length()>=60){
			cout<<cur<<endl;
			cur=nxt;
		}
		else 
		{
			if(cur.length()>0)cur+=' '+nxt;
			else cur+=nxt;
		}
	}
	if(cur.length())cout<<cur<<endl;
}
