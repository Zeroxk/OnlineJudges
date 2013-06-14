#include <cstdio>

unsigned long memo[4000001];

int main(void) {
    unsigned long n = 4000000;
    printf("Finding sum for fib(%lu)\n", n);
    
    memo[0] = 0;
    memo[1] = 1;

    unsigned long i = 2;
    unsigned long sum = 0;
    while(memo[i-1] <= n) {
        memo[i] = memo[i-1] + memo[i-2];
        if(memo[i] % 2 == 0) {
            sum += memo[i];
        }
        i++;
    }
    
    printf("Sum is %lu\n", sum);
    return 0;
}
