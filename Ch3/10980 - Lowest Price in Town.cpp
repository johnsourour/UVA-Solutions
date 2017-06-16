#include<bits/stdc++.h>
using namespace std;

#define INF 100000000.0

int m;
double  T[21][105];
pair<int,double> A[21];
double DP(int i, int k)
{
	if(i==m)return INF;
	if(k<=0)return 0.0;
	
	double &v=T[i][k];
	if(v==-1.0)
	{
		v=min(DP(i+1,k),A[i].second+DP(i,k-A[i].first));
	}
	return v;
}


int main()
{
	int num,M,K=1,pos;
	string s;
	double t;
	while(scanf("%lf",&t)!=EOF)
	{
		num=1;
	
		A[0]=make_pair(num,t);
		scanf("%d",&m);
		m++;
		for(int i=1;i<m;i++)
		{
			scanf("%d %lf",&num,&t);
			A[i]=make_pair(num,t);
		}
		fill(&T[0][0],&T[21][0],-1.0);
		printf("Case %d:\n",K++);
		getline(cin, s);
		getline(cin, s);
		while(s.length()>0)
		{
			while(s.at(0)==' ')s.erase(0,1);
			pos=s.find(' ');
			M=stoi(s.substr(0,pos));
			s.erase(0,pos);
			printf("Buy %d for $%.2f\n",M,DP(0,M));
		}
		
	}
	return 0;
}
