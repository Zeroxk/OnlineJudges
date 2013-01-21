#include <stdio.h>
#define REP(i,n) for(int _n=(n),i=0; i<_n;i++)
using namespace std;
int main() {

	int n;
	scanf("%d",&n);

	REP(i,n) {

		int a,b,c,middle;
		scanf("%d%d%d",&a,&b,&c);
printf("%d %d %d\n",a,b,c);		
if(a < b < c || c < b < a) {
			middle = b;
		}else if(b < a < c || c < a < b) {
			middle = a;
	}else if (a < c < b || b < c < a) {
			middle = c;
		}
		
		printf("Case %d: %d\n",(i+1),middle);
	}
	return 0;
	
}
