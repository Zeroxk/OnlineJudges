#include <stdio.h>
#define REP(i,n) for(int _n=(n),i=0; i<_n;i++)
int main() {

	int n;
	scanf("%d",&n);

	REP(i,n) {

		int a,b,c,middle;
		scanf("%d%d%d",&a,&b,&c);
		
		if((a < b && b < c) || (c < b && b < a)) {
			middle = b;
		}else if((b < a && a < c) || (c < a && a < b)) {
			middle = a;
		}else if ((a < c && c < b) || (b < c && c < a)) {
			middle = c;
		}
		
		printf("Case %d: %d\n",(i+1),middle);
	}
	return 0;
	
}
