#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

int findProd(string num) {
    int prod = 1;
    for(int i=0; i<num.size(); i++) {
        prod *= num[i]-'0';
    }

    return prod;
}

int main(void) {

    string num;
    cin >> num;

    string biggest = "0";
    for(int i=0; i<num.size()-5; i++) {
        string sub = num.substr(i,5);
        //cout << "Sub is " << sub << endl;
        if(sub.find("0") == string::npos) {
            biggest = atoi(biggest.c_str()) < atoi(sub.c_str()) ? sub : biggest;
        }
    }

    int ans = findProd(biggest);
    cout << "Biggest number " << biggest << endl;
    cout << "Largest consecutive 5-digit number is " << ans << endl;

    return 0;
}
