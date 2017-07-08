#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int getNum(string &s)
{
	string tmp="";
	while(s.length() && s.at(0)!=' ')
	{
		tmp+=s.at(0);
		s.erase(0,1);
	}
	int mul=1;
	if(tmp.at(0)=='-')
	{
		tmp.erase(0,1);
		mul=-1;
	}
	if(s.length())s.erase(0,1);
	return mul*stoi(tmp);
}
double getDistance(int x, int y, int a, int b)
{
	return 120.0*(sqrt(pow(x-a,2)+pow(y-b,2))/20000.0);
}
int main()
{
	int T,x,y,x2,y2,mul,f,t,cnt;
	double dist;
	string s,tmp;
	scanf("%d",&T);
	getline(cin,s);
	getline(cin,s);
	while(T--)
	{
		cnt=0;
		scanf("%d%d",&x,&y);
		getline(cin,s);
		double mins=0;
		while(getline(cin,s) && s!="")
		{
			x=getNum(s);
			y=getNum(s);
			x2=getNum(s);
			y2=getNum(s);
			dist=getDistance(x,y,x2,y2);
			mins+=dist;
		}
		int ans=round(mins);
		printf("%d:%02d\n",ans/60,ans%60);
		if(T)printf("\n");
	}

	return 0;
}
