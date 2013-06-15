#include <cstdio>
#include <cmath>

using namespace std;

int main(void) {
    
    bool found = false;
    int i = 0;
    int s = 100000;
    while(!found && i<s) {  
        i++;
        int aa = i*i;
        for(int j=i+1; j<s; j++) {
            int bb = j*j;
            int c = (int) (sqrt(aa+bb)+0.5);

            //printf("c is %d\n", c);
            if(c*c == aa+bb && i+j+c == s) {
                printf("a: %d b: %d c: %d\n", i,j,c);
                printf("Product: %d\n", i*j*c);
                found = true;
                break;
            }
        }
    }

    return 0;
}
