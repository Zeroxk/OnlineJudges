#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

string findPermutation(string a, string b) {
    if(a == "" || b == "") return "";

    vector<int> countA = vector<int>(26);
    vector<int> countB = vector<int>(26);

    for(int i=0; i<a.size(); i++) {
        countA[a[i] - 'a']++;
    }

    for(int i=0; i<b.size(); i++) {
        countB[b[i] - 'a']++;
    }

    string str = "";
    for(int i=0; i<26; i++) {
        for(int j= min(countA[i], countB[i])-1; j >= 0; j--) {
            str += (i + 'a');
        }
    }

    return str;
}

int main(void) {
    
    vector<string> input = vector<string>();

    string a = "";
    while(getline(cin, a)) {
        input.push_back(a);
    }

    /*for(int i=0; i<input.size(); i++) {
        cout << input[i] << endl;
    }*/

    for(int i=0; i<input.size()-1; i += 2) {
        string perm = findPermutation(input[i], input[i+1]);
        cout << perm << endl;
    }
    
    return 0;
}

