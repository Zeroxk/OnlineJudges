#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    vector<int> tasks;
    while(n--) {
        int d,t;
        scanf("%d %d", &d, &t);
        tasks.push_back(t-d);
    }

    for(int i=0; i<tasks.size(); i++) {

    }
}
