#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,K=1,N,cnt;
	vector<bool> field;
	char tmp;
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d",&N);
		cnt=0;
		field.clear();
		field.resize(N);
		for(int i=0;i<N;i++)
		{
			scanf(" %c",&tmp);
			if(tmp=='.')field[i]=true;
		}
		for(int i=0;i<N;i++)
		{
			
			if(field[i])
			{
				field[i]=field[i+1]=field[i+2]=false;
				cnt++;
			}
		}
		printf("Case %d: %d\n",K,cnt);
		K++;
	}
	return 0;
}
