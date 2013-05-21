#include <cstdio>
#include <cmath>

int main(void) {

    unsigned long n;
    scanf("%lu", &n);

    unsigned long long rectangles = 0;
    for(int i=1; i<=sqrt(n); i++) {
        rectangles += (n/i)-i+1;
    }

    printf("%llu\n", rectangles);

    return 0;
}
