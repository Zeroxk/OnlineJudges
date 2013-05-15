#include <cstdio>

int cherriesX[100], cherriesY[100];
int n;

bool check(int a, int b) {

    int pos = 0; 
    int neg  = 0;;
    for(int i=0; i<(2*n); i++) {
        int cherry = a*cherriesX[i]+b*cherriesY[i];
        if(cherry == 0) return false;

        if(cherry > 0) {
            pos++;
        }else {
            neg++;
        }
    }

    if(pos == neg) {
        return true;
    }

    return false;

}

int main(void) {

    while(true) {
        
        scanf("%d", &n);

        if(n == 0) break;

        for(int i=0; i<2*n; i++) {
            int x,y;
            scanf("%d %d", &x, &y);
            cherriesX[i] = x;
            cherriesY[i] = y;
        }

        int A,B;
        bool stop = false;
        for(int i=-500; i<=500; i++) {
            for(int j=-500; j<=500; j++) {
                
                if(check(i,j)) {
                    A=i;
                    B=j;
                    stop = true;
                    break;
                    
                }
            }
            if(stop) break;
        }
        printf("%d %d\n", A, B);
    }

    return 0;
}
