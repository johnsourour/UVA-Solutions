#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,A,B,C,x,y,z;
	bool sol=false;
	scanf("%d",&N);
	while(N--)
	{
		sol=false;
		scanf("%d%d%d",&A,&B,&C);
		for (x = -22; x <= 22 && !sol; x++) if (x * x <= C)
			for (y = -100; y <= 100 && !sol; y++) if (y != x && x * x + y * y <= C)
				for (z = -100; z <= 100 && !sol; z++)
					if (z != x && z != y &&
							x + y + z == A && x * y * z == B && x * x + y * y + z * z == C) {
					
						sol = true; }
						if(sol)		printf("%d %d %d\n", x-1, y-1, z-1);
						else printf("No solution.\n");
	}
	return 0;
}
