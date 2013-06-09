#include <cstdio>
#include <algorithm>

using namespace std;

const unsigned int SIZE = 1000000;

int main(void) {
    unsigned int a,b;
    unsigned int memo[SIZE];
    //printf("%u\n", sizeof(memo));
    while(scanf("%u %u", &a, &b) != EOF) {
        unsigned int maxCycles = 0;
        
        bool swapped = false;
        if(b < a) {
            swapped = true;
            swap(a,b);
        }

        for(unsigned int i=a; i<=b; i++) {
            unsigned int tmp =1;
            if(memo[i-1] == 0) {
                //printf("Undiscovered cycle length\n");

                unsigned int n = i;

                while(n != 1) {
                    //printf("n is %u\n", n);
                    tmp ++;
                    
                    n = n & 1 == 1 ? (3*n)+1 : n >> 1;
                    //n = n % 2 == 1 ? (3*n)+1 : n >> 1; 
                }
                memo[i-1] = tmp;
            }else {
                //printf("Already found\n");
                tmp = memo[i-1];
            }

            maxCycles = max(maxCycles, tmp);
        }
        
        if(!swapped) {
            printf("%u %u %u\n", a, b, maxCycles);
        }else {
            printf("%u %u %u\n", b,a, maxCycles);
        }
    }

    return 0;
}
