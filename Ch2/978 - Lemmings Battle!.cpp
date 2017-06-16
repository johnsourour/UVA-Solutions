#include <bits/stdc++.h>
using namespace std;
int main() {
	int N,B,SG,SB,t;
	vector<int> bl,gl;
	multiset<int> green,blue; 
	multiset<int>::iterator git,bit;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d%d",&B,&SG,&SB);
		blue.clear();
		green.clear();
		while(SG--)
		{
			scanf("%d",&t);
			green.insert(t);
		}
		while(SB--)
		{
			scanf("%d",&t);
			blue.insert(t);
		}
		while(!blue.empty() && !green.empty())
		{
			
			int round=0;
			bl.clear();
			gl.clear();
			while(round<B && !blue.empty() && !green.empty())
			{
				if(!blue.empty())
				{
					bl.push_back(*blue.rbegin());
					bit=blue.end();
					bit--;
					blue.erase(bit);
				}
				if(!green.empty())
				{
					gl.push_back(*green.rbegin());
					git=green.end();
					git--;
					green.erase(git);
				}
				round++;
			}
			for(int i=0;i<round;i++)
			{
				if(bl[i]<gl[i]){
					green.insert(gl[i]-bl[i]);
				}
				else if(bl[i]>gl[i]){
					blue.insert(bl[i]-gl[i]);
				}
			}
			
		}
		if(blue.empty() && green.empty())printf("green and blue died\n");
		else if(blue.empty())
		{
			printf("green wins\n");
			while(!green.empty())
			{
				printf("%d\n",*green.rbegin());
				git=green.end();
					git--;
					green.erase(git);
			}
		}
		else
		{
			printf("blue wins\n");
			while(!blue.empty())
			{
				printf("%d\n",*blue.rbegin());
				bit=blue.end();
					bit--;
					blue.erase(bit);
			}
		}
		if(N!=0)printf("\n");
	}
	return 0;
}
