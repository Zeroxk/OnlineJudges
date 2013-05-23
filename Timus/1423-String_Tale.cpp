#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int table[500001];

int preCompute(string w) {
    
    int pos = 2;
    int i = 0;

    table[0] = -1;
    table[1] = 0;

    while(pos < w.size()) {
        if(w[pos-1] == w[i]) {
            i++;
            table[pos] = i;
            pos++;
        }else if(i > 0) {
            i = table[i];
        }else {
            table[pos] = 0;
            pos++;
        }
    }

}

int runKMP(string s, string w) {
    
    int m = 0;
    int i = 0;

    while( (m+i) < s.size() ) {
        if(w[i] == s[m+i]) {
            if(i == w.size()-1) return (w.size() - m);

            i++;
        }else {
            m = m + i - table[i];
            if(table[i] > -1) {
                i = table[i];
            }else {
                i = 0;
            }
        }
    }

    return -1;

}

int main(void) {
    int n;
    cin >> n;

    string s = "";
    string w = "";
    cin >> s;
    cin >> w;

    if(strncmp(s.c_str(),w.c_str(), s.size()) == 0) {
        cout << 0 << endl;
    }else {
        s.append(s);

        //cout << "S " << s << " W " << w << endl;
        preCompute(w);

        /*for(int i=0; i<w.size(); i++) {
          cout << table[i];
          }
          cout << endl;*/

        int ans = runKMP(s,w);

        cout << ans << endl;

    }

        return 0;
}
