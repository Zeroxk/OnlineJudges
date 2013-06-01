#include <cstdio>
#include <vector>

using namespace std;

vector<int> cuts;

int main(void) {
    
    while(true) {
        int length;
        scanf("%d", &length);
        
        if(length == 0) break;

        int n;
        scanf("%d", &n);

        while(n--) {
            int cut;
            scanf("%d", &cut);
            cuts.push_back(cut);
        }
        
        cuts[0] = 0;
        cuts.back = length;

    }

    return 0;
}

