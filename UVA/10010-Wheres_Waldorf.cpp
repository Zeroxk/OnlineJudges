#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

void findWords(char grid[][501], vector<string> words, int rows, int cols) {
    
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            
            for(int w=0; w<words.size(); w++) {
                if(grid[i][j] == w[i][0]) {
                    
                    //Searching right
                    //Searching left
                    //Searching down
                    //Searching up
                    //Searching diagonals

                }
            }

        }
    }

}

int main(void) {

    int cases;
    cin >> cases;

    cout << endl;
    while(cases--) {
        int rows, cols;
        cin >> rows >> cols;

        cout << "rows " << rows << " cols " << cols << endl;
        char grid[501][501];
        for(int r=0; r<=rows; r++) {
           string str = "";
           getline(cin, str);
           for(int i=0; i<cols; i++) {
                grid[r][i] = tolower(str[i]);
           }
        }

        int k;
        cin >> k;
        cout << "# words " << k << endl;
        vector<string> words = vector<string>();

        for(int w = 0; w<=k; w++) {
            string str = "";
            getline(cin, str);
            for(int i=0; i<str.size(); i++) {
                str[i] = tolower(str[i]);
            }
            words.push_back(str);
        }

        cout << "Grid";
        for(int i=0; i<=rows; i++) {
            for(int j=0; j<cols; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        
        cout << "\nWords";
        for(int i=0; i<words.size(); i++) {
            cout << words[i] << endl;
        }

        findWords(grid, words, rows, cols);
        
    }

    return 0;
}
