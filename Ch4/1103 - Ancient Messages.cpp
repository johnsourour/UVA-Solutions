#include<bits/stdc++.h>
using namespace std;
int W,H,grid[205][405];
int dr[] = {1,0,-1, 0}; 
int dc[] = {0,1, 0,-1};
vector<char> comp;
char letter(int n)
{
	switch(n)
	{
		case 0: return 'W';
		case 1: return 'A';
		case 2: return 'K';
		case 3: return 'J';
		case 4: return 'S';
		case 5: return 'D';
	}
}
string hexToBin(char c)
{
	switch(c){
		case '0':return "0000";
		case '1':return "0001";
		case '2':return "0010";
		case '3':return "0011";
		case '4':return "0100";
		case '5':return "0101";
		case '6':return "0110";
		case '7':return "0111";
		case '8':return "1000";
		case '9':return "1001";
		case 'a':return "1010";
		case 'b':return "1011";
		case 'c':return "1100";
		case 'd':return "1101";
		case 'e':return "1110";
		case 'f':return "1111";
	}
}
void floodfill(int r, int c, int c1, int c2) 
{
	if (r < 0 || r >= H || c < 0 || c >= W) return; 
	if (grid[r][c] != c1)return; 
	grid[r][c] = c2; 
	for (int d = 0; d < 4; d++)
		floodfill(r + dr[d], c + dc[d], c1, c2);

}
int floodfill2(int r, int c, int c1, int c2) 
{
	if (r < 0 || r >= H || c < 0 || c >= W) return 0; 
	if (grid[r][c] == c2) return 0; 
	if (grid[r][c] != c1) {floodfill(r,c,0,-1);return 1;} 
	int ans = 0; 
	grid[r][c] = c2; 
	for (int d = 0; d < 4; d++)
		ans+=floodfill2(r + dr[d], c + dc[d], c1, c2);
	return ans;
}
int main()
{	
	char c;
	int K=1;
	string s;
	scanf("%d%d",&H,&W);
	while(H||W)
	{
		comp.clear();
		int e,st;
		for(int i=0;i<H;i++)
		{
			st=0;
			e=4;
			for(int k=0;k<W;k++)
			{
				scanf(" %c",&c);
				s=hexToBin(c);
				for(int j=st;j<e;j++)
				{
					grid[i][j]=s.at(0)-'0';
					s.erase(0,1);
				}
				st+=4;
				e+=4;
			}
		}
		W*=4;
		for(int i=0;i<H;i++)floodfill(i,0,0,-1);
		for(int j=0;j<W;j++)floodfill(0,j,0,-1);
		for(int i=0;i<H;i++)floodfill(i,W-1,0,-1);
		for(int j=0;j<W;j++)floodfill(H-1,j,0,-1);
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				
			if(grid[i][j]==1)
			{
			comp.push_back(letter(floodfill2(i,j,1,-1)));
			}
	//		cout<<grid[i][j]<<" ";
			}
	//		cout<<endl;
		}
		printf("Case %d: ",K++);
		sort(comp.begin(),comp.end());
		for(char i:comp)printf("%c",i);
		printf("\n");
		scanf("%d%d",&H,&W);
	}
	return 0;
}
