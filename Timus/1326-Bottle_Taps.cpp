#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    vector<int> storePrices;
    while(n--) {
        int price;
        scanf("%d", &price);
        storePrices.push_back(price);
    }

    int offers;
    scanf("%d", &offers);

    vector<vector<int> > offerList = vector<vector<int> >(offers);
    for(int i=0; i<offers; i++) {
        int price, tapsInSet;
        scanf("%d %d", &price, &tapsInSet);

        offerList[i].push_back(price);
        for(int j=0; j<tapsInSet; j++) {
            int setPrice;
            scanf("%d", &setPrice);
            offerList[i].push_back(setPrice);
        }
    }

    int tapsBuy;
    scanf("%d", &tapsBuy);

    vector<int> wantedTaps;
    while(tapsBuy--) {
        int tap;
        scanf("%d", &tap);
        wantedTaps.push_back(tap);
    }

    return 0;
}
