#include <bits/stdc++.h>
using namespace std;
int t,S,Q;
stack<int> c;
vector<queue<int> > vq;
void station(int i)
{

	while(!c.empty() && (c.top()==i || vq[i].size()<Q) )
	{
	   // op=true;
		if(c.top()!=i){ vq[i].push(c.top());}
		c.pop();
		t++;
	}
//	while(!c.empty()&&){t++;c.pop();}
	while(c.size()<S && !vq[i].empty())
	{
		c.push(vq[i].front());
		vq[i].pop();
		t++;
	}
}
bool doneQ()
{
	for(int i=0;i<vq.size();i++)
	{
		if(!vq[i].empty()){return false;}
	}
	return true;
}
int main() {
	int C,N,k,kk;
	scanf("%d",&C);
	while(C--)
	{
		scanf("%d%d%d",&N,&S,&Q);
		t=-2;
		vq.clear();
		vq.resize(N);
		
		for(int i=0;i<N;i++)
		{
			scanf("%d",&k);
			
			while(k--)
			{
				scanf("%d",&kk);
				vq[i].push(kk-1);
			}
			
		}
		int i=0;
		bool flag=false;
		while(!doneQ() || !c.empty())
		{
			
			station(i);
			i=(i+1)%N;
			t+=2;
		}
		printf("%d\n",t);
	}
	return 0;
}
