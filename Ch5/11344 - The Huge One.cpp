#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool div(string s,int n)
{
	if(n==1)return true;
	else if(n==3 || n==9)
	{
		int sum=0;
		for(int i=0;i<s.length();i++)sum+=s.at(i)-'0';
		return sum%n==0;
	}
	else if(n==2)
	{
		return (s.at(s.length()-1)-'0')%2==0;
	}
	else if(n==4 || n==8)
	{
		while(s.length()>n/2)s.erase(0,1);
		return stoi(s)%n==0;
	}
	else if(n==5)
	{
		int last=(s.at(s.length()-1)-'0');
		return last==0||last==5;
	}
	else if(n==6 || n==12)return div(s,3)&&div(s,n/3);
	else if(n==10){ 
		int last=(s.at(s.length()-1)-'0');
		return last==0;
	}
	else if(n==11)
	{
		int sum=0;bool flag=true;
		for(int i=0;i<s.length();i++)
		{
			if(flag)sum+=s.at(i)-'0';
			else sum-=s.at(i)-'0';
			flag=!flag;
		}
		return sum%11==0;
	}
	else 
	{
		int dd[]={1,-3,2};
		string tmp="";int cnt=0,cur=0,num=0;
		for(int i=0;i<s.length();i++)
		{
			if(cnt==2)
			{
				num+=stoi(tmp)*dd[cur];
				tmp="";
				cur=(cur+1)%3;
				cnt=0;
			}
			tmp+=s.at(i);
			cnt++;
		}
		if(tmp.length()==1)num+=stoi(tmp+'0')*dd[cur];
		else if(tmp.length()==2)num+=stoi(tmp)*dd[cur];
	
	
		return num%7==0;
	}
	
}
int main()
{
	int T,m,t;
	string num;
	scanf("%d",&T);
	while(T--)
	{
		bool wonder=true;
		cin>>num>>m;
		while(m--)
		{
			scanf("%d",&t);
			if(wonder)wonder=div(num,t);
		}
		printf("%s - ",num.c_str());
		if(wonder)printf("Wonderful.\n");
		else printf("Simple.\n");
		
	}
}
