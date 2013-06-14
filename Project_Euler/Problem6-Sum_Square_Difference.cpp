#include <cstdio>

int main(void) {
    
    int n = 100;

    int sumSq = 0;
    for(int i=1; i<=n; i++) {
        sumSq += i*i;
    }

    printf("Sum of squares %d\n", sumSq);
    
    int sum = (n*(n+1))/2;
    int sqSum = sum*sum;

    printf("Square of sum %d\n", sqSum);

    printf("Difference %d\n", sqSum-sumSq);

    return 0;
}
