#include <sstream>
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
    unsigned int start = 0;
    unsigned int end = str.size()-1;
    //cout << "string " << str << endl;
    while(start <= end) {
        if(str[start] != str[end]) {
            return false;
        }

        start++;
        end--;
    }

    cout << str << " is palindrome" << endl;
    return true;
}

int main(void) {
    
    unsigned int ans = 0;

    for(unsigned int i=100; i<999; i++) {
        for(unsigned int j=100; j<=999; j++) {
            unsigned int n = i*j;
            stringstream ss;
            ss << n;
            string str = ss.str();
            if(isPalindrome(str)) {
                ans = max(ans, n);
            }
        }
    }

    cout << "Largest palindrome: " << ans << endl;

    return 0;
}
