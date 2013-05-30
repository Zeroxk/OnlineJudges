#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
    
    while(true) {
        int length;
        scanf("%d", &length);
        
        if(length == 0) break;

        int n;
        scanf("%d", &n);

        vector<int> cuts = vector<int>();
        while(n--) {
            int cut;
            scanf("%d", &cut);
            cuts.push_back(cut);
        }

    }

    return 0;
}

