#include<bits/stdc++.h>
using namespace std;
int q[8];
int cur[8];
int mx;
bitset<30> rw, ld, rd; 
void backtrack(int c) {
	if (c == 8) { 
		int mov=8;
		for(int i=0;i<8;i++)
		{
			if(q[i]==cur[i])mov--;
		}
		mx=min(mx,mov);
		return;
	} 
	for (int r = 0; r < 8; r++)
	if (!rw[r] && !ld[r - c + 7] && !rd[r + c])
	{
		rw[r] = ld[r - c + 7] = rd[r + c] = true; 
		cur[c]=r+1;
		backtrack(c + 1);
		rw[r] = ld[r - c + 7] = rd[r + c] = false; 
	} 
}
int main()
{
	int K=1,t;
	while(scanf("%d%d%d%d%d%d%d%d",&q[0],&q[1],&q[2],&q[3],&q[4],&q[5],&q[6],&q[7])!=EOF)
	{
		mx=8;
		backtrack(0);
		printf("Case %d: %d\n",K,mx);
		K++;
	}
	return 0;
}
