#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main(void) {

    int n,m;
    scanf("%d %d", &n, &m);

    vector<bool> chosen (2*n, false);
    vector<bool> canChoose (2*n, true);
    for(int i=0; i<m; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        a--; b--;

        if(canChoose[a] && !chosen[a]) {
            //printf("Chose %d\n", a+1);
            chosen[a] = true;
            if(a % 2 == 1) {
                canChoose[a-1] = false;
            }else {
                canChoose[a+1] = false;
            }
            canChoose[b] = false;
        }
        
        if(canChoose[b] && !chosen[b]) {
            //printf("Chose %d\n", b+1);
            chosen[b] = true;
            if(b % 2 == 1) {
                canChoose[b-1] = false;
            }else {
                canChoose[b+1] = false;
            }
            canChoose[a] = false;
        }

    }

    bool nie = false;
    for(int i=0; i<2*n; i+=2) {
        if(canChoose[i] && canChoose[i+1]) {
            //printf("Can choose %d\n", i+1);
            chosen[i] = true;
        }

        if(!chosen[i] && !chosen[i+1]) {
            nie = true;
            break;
        }
    }

    if(nie) {
        printf("NIE\n");
    }else {
        for(int i=0; i<2*n; i++) {
            //cout << i << " is " << chosen[i] << endl;

            if(chosen[i]) {
                printf("%d\n", i+1);
            }
        }

    }

    return 0;
}
