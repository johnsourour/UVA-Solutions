#include<bits/stdc++.h>
using namespace std;

#define North 0
#define East 1
#define West 3
#define South 2
pair<int,int> getNext(pair<int,int>cur, int dir)
{
	int x=cur.first,y=cur.second;
	if(dir==0)	x--;
	else if(dir==1) y++;
	else if(dir==2) x++;
	else y--;
	return make_pair(x,y);
}
int main()
{	
	char c;
	int  mx,cnt,dir,N,M,S,A[105][105];
	pair<int, int> cur,nxt;
	scanf("%d%d%d",&N,&M,&S);
	while(N||M||S)
	{
		mx=cnt=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++)
			{
				scanf(" %c",&c);
		//		cout<<c;
				if(c=='*')
				{	A[i][j]=1;mx++;}
				else if(c=='.')
					A[i][j]=0;
				else if(c=='#')
					A[i][j]=-1;
				else 
				{
						A[i][j]=0;
					cur=make_pair(i,j);
					if(c=='N')dir=North;
					else if(c=='S')dir=South;
					else if(c=='L')dir=East;
					else dir=West;
				}
			}
		//	cout<<endl;
		}
			for(int i=0;i<S;i++)
			{
				scanf(" %c",&c);
				if(c=='F')
				{
					nxt=getNext(cur,dir);
					int x=nxt.first,y=nxt.second;
					if(x < 0 || y<0 || x>=N || y>=M || A[x][y]==-1)continue;
					cur=nxt;
					cnt+=A[x][y];
					
					A[x][y]=0;
				}
				else if(c=='D')
				{
					dir=(dir+1)%4;
				}
				else
				{
						dir=(dir-1)%4;
						if(dir<0)dir=3;
				}
			}
		printf("%d\n",cnt);
	scanf("%d%d%d",&N,&M,&S);	
	}
	return 0;
}
