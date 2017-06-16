#include<bits/stdc++.h>
using namespace std;
vector<int> st,A,lazy;
int n;
void build(int p, int L, int R)
{
	if(L==R) st[p]=A[L];
	else { 
		build(p<<1 , L , (L + R) / 2);
		build((p<<1) +1, (L + R) / 2 + 1, R );
		int p1 = st[(p<<1) +1], p2 = st[p<<1];
		st[p] = p1+p2;
    }
}
int rmqRange(int p, int L, int R, int i, int j)
{
	if (L > R || j < L || i > R) return 0; 
	if(lazy[p] != 0)
	{
		if(lazy[p]==1)st[p]= (R-L + 1); 
		else if(lazy[p]==2)st[p]=0;
		else st[p]=abs(st[p]-(R-L+1));
     	if(R!=L)
		{
			if(lazy[p]!=3)
			{
				lazy[p<<1]=lazy[p];
				lazy[(p<<1) +1 ]=lazy[p];
			}
			else 
			{	lazy[(p<<1)]=(lazy[(p<<1)]==2)?1:((lazy[(p<<1)]==3)?0:(lazy[(p<<1)]==0)?3:2);
				lazy[(p<<1) +1 ]=(lazy[(p<<1) +1]==2)?1:((lazy[(p<<1) + 1]==3)?0:(lazy[(p<<1) + 1]==0)?3:2);
			}
			
		
		}
		lazy[p]=0;	    
	
	}
	
    if(L >= i && R <= j)  
        return st[p];
    int mid = (L+R) / 2;
    int p1 = rmqRange(p<<1,L, mid, i, j);         // Query left child
    int p2 = rmqRange((p<<1) + 1,mid+1, R,  i, j); // Query right child
    return (p1 + p2);

}
int rmqRange(int i, int j) { return rmqRange(1, 0, n - 1, i, j); } // current segment outside query range

void updateRange(int p, int L, int R, int i,int j, int num)
{
	if(lazy[p]!=0)
	{
		
	    if(lazy[p]==1)st[p]= (R-L + 1); 
		else if(lazy[p]==2)st[p]=0;
		else st[p]=abs(st[p]-(R-L+1));
		if(L!=R)
		{
		    if(lazy[p]!=3)
			{
				lazy[p<<1]=lazy[p];
				lazy[(p<<1) +1 ]=lazy[p];
			}
			else 
			{
				lazy[(p<<1)]=(lazy[(p<<1)]==2)?1:((lazy[(p<<1)]==3)?0:((lazy[(p<<1)]==0)?3:2));
				lazy[(p<<1) +1 ]=(lazy[(p<<1) +1]==2)?1:((lazy[(p<<1) + 1]==3)?0:(lazy[(p<<1) + 1]==0)?3:2);
			
			}
		}
		lazy[p]=0;
	}
	if(L>R || R<i || L>j)return;
	if(i<=L && j>=R)
	{
		if(num==1)st[p]=(R-L+1);
		else if(num==2)st[p]=0;
		else  st[p]=abs(st[p]-(R-L+1));
		if(L!=R)
		{
			if(num!=3)
			{
				lazy[p<<1]=num;
				lazy[(p<<1) +1 ]=num;
			}
			else
			{
				lazy[(p<<1)]=(lazy[(p<<1)]==2)?1:((lazy[(p<<1)]==3)?0:(lazy[(p<<1)]==0)?3:2);
				lazy[(p<<1) +1 ]=(lazy[(p<<1) +1]==2)?1:((lazy[(p<<1) + 1]==3)?0:(lazy[(p<<1) + 1]==0)?3:2);
			}
			
		}
		return;
	}
	
	updateRange(p<<1 , L,(L+R)/2,i, j , num);
	updateRange((p<<1 )+ 1 ,((L+R)/2) + 1 ,R, i, j , num);
	st[p]=st[p<<1] + st[(p<<1) + 1];
}
void updateRange(int i,int j, int num)
{
	updateRange(1,0,n-1,i,j,num);
}

int main() {
	int K,T,QN,M,Q,p1,p2,cases=1;
	scanf("%d",&T);
	char c[55],qt;
	string s;
	while(T--)
	{
		A.clear();
		scanf("%d",&M);
		while(M--)
		{
			scanf("%d",&K);
			scanf("%s",&c[0],sizeof c);
			s=c;
			for(int i=0;i<K*s.length();i++)
			{
				A.push_back(s.at(i%s.length())-'0');
			}
		}
		n=A.size();
		st.clear();
		st.resize(4*n);
		lazy.clear();
		lazy.resize(4*n);
		build(1,0,n-1);
		printf("Case %d:\n",cases);
		QN=1;
		scanf("%d",&Q);
		while(Q--)
		{
			
			
			scanf(" %c%d%d",&qt,&p1,&p2);
			if(qt=='F')
			{
				updateRange(p1,p2,1);
			}
			else if(qt=='E')
			{
				updateRange(p1,p2,2);

			}
			else if(qt=='I')
			{
				updateRange(p1,p2,3);
					

			}
			
			else
			{
				
				printf("Q%d: %d\n",QN,rmqRange(p1,p2));
				QN++;
			}
		}
		
		
		
		cases++;
	}
	return 0;
}
