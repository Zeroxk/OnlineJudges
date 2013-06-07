#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    while(scanf("%d", &n) != EOF) {

        vector<int> v;
        while(n--) {
            int a;
            scanf("%d", &a);
            v.push_back(a);
        }

        vector<int> diffs;
        for(int i=0; i<v.size()-1; i++) {
            int diff = abs(v[i]-v[i+1]);
            diffs.push_back(diff);
        }

        stable_sort(diffs.begin(), diffs.end());

        bool jolly = true;
        for(int i=0; i<diffs.size(); i++) {
            //printf("v %d diff %d\n", v[i], diffs[i]); 
            if(diffs[i] != i+1) {
                jolly = false;
                break;
            }
        }

        if(jolly) {
            printf("Jolly\n");
        }else {
            printf("Not jolly\n");
        }
    }

    return 0;
}
