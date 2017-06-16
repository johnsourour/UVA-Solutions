#include <bits/stdc++.h>
using namespace std;
struct contestant
{
	int num,penalty,psolved;
	int cpenalty[9];
	bool prs[9];
};
struct comp{
	bool operator()(contestant const &a, contestant const &b)
	{
		if(a.psolved>b.psolved) return true;
		else if(a.psolved<b.psolved)return false;
		else if (a.penalty<b.penalty)return true;
		else if(a.penalty>b.penalty)return false;
		else return a.num<b.num;
	}
};
int main() {
	int N;
	vector<contestant> P;
	scanf("%d",&N);
	int c,p,t;
	char ss[50],v;
	getchar(); getchar();
	while(N--)
	{
		
		P.clear();
		c=1;
		P.resize(100);
		while(fgets(ss, sizeof ss, stdin) && ss[0]!='\n')
		{
		
			sscanf(ss,"%d %d %d %c",&c,&p,&t,&v);
			
			P[c-1].num=c;
			if(!(P[c-1].prs[p-1]))
			{
				
				
				if(v=='C'){
					P[c-1].penalty+=(t+P[c-1].cpenalty[p-1]);
					P[c-1].psolved++;
					P[c-1].prs[p-1]=true;
				}
				else if(v=='I')
				{
					P[c-1].cpenalty[p-1]+=20;
				}
			}
		
			
		}
		sort(P.begin(),P.end(),comp());
		for(int i=0;i<100;i++)
		{
			if(P[i].num!=0)printf("%d %d %d\n",P[i].num,P[i].psolved,P[i].penalty);
		}
		if(N!=0)printf("\n");
	}
	return 0;
}
