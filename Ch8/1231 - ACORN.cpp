#include<bits/stdc++.h>
using namespace std;
#define MAX 2005

int tree[MAX][MAX];
int mem[MAX];
 
int main(){
	int tc, t, h, f, a, b;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d%d%d", &t, &h, &f);
		memset(tree, 0, sizeof tree);
		memset(mem, 0, sizeof mem);
		
		for(int k=1;k<=t;k++){
			scanf("%d", &a);
			for(int i=0;i<a;i++){
				scanf("%d", &b);
				tree[k][b]++;
			}
		}
		
		for(int i=1;i<=t;i++)
			mem[h]=max(mem[h],tree[i][h]);
	
		for(int b = h-1; b>=0; b--){
			for(int k=1; k<=t; k++)
			{
				tree[k][b]+=max(tree[k][b+1], b+f<=h? mem[b+f]:0);
				mem[b] = max(mem[b], tree[k][b]);
			}
		}
		printf("%d\n", mem[0]);
	}
	return 0;
}