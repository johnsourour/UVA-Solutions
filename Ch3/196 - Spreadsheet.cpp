#include<bits/stdc++.h>
using namespace std;
int r,c;
string A[1000][18290];
int DP(int i,int j)
{
	
	if(A[i][j].at(0)!='=')return stoi(A[i][j]);
	vector<pair<int,int> >p;
	string tmp=A[i][j],cur="";
	int ans=0,x,y;
	while(tmp.length()>0)
	{
		if(tmp.at(0)=='=' || tmp.at(0)=='+')
		{
			if(cur!="")
			{
				x=y=0;
				while(cur.length()>0)
				{
					char c=cur.at(0);
					if(c<='Z' && c>='A')y=(y*26)+(c-'A'+1);
					else x=(x*10)+(c-'0');
					cur.erase(0,1);
				}
				p.push_back(make_pair(x-1,y-1));
			}
			tmp.erase(0,1);
		}
		
		cur+=tmp.at(0);
		tmp.erase(0,1);
	}
	if(cur!="")
	{
		x=y=0;
		while(cur.length()>0)
		{
			char c=cur.at(0);
			if(c<='Z' && c>='A')
			y=(y*26)+(c-'A'+1);
			else x=(x*10)+(c-'0');
			cur.erase(0,1);
		}
			p.push_back(make_pair(x-1,y-1));
	}
	for(pair<int,int> pp:p){ans+=DP(pp.first,pp.second);}
	
	A[i][j]=to_string(ans);
	return ans;
	
}
int main()
{
	int K;
	string tmp;
	scanf("%d",&K);
	while(K--)
	{
		scanf("%d%d",&c,&r);
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				cin>>A[i][j];
				
			}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
			{
				
				tmp=A[i][j];
				if(tmp.at(0)=='=')DP(i,j);
				cout<<A[i][j];
				if(j<c-1)cout<<" ";
				
				
			}
			cout<<endl;}
			
			
	}
}
