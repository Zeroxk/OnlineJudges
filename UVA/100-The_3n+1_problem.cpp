#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
    unsigned int a,b;
    while(scanf("%u %u", &a, &b) != EOF) {
        unsigned int maxCycles = 0;
        
        bool swapped = false;
        if(b < a) {
            swapped = true;
            swap(a,b);
        }

        for(unsigned int i=a; i<=b; i++) {
           unsigned int tmp =1;
           unsigned int n = i;
           while(n != 1) {
               tmp++;
               n = n % 2 == 1 ? (3*n)+1 : n/2; 
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
