#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

void findWords(char grid[][52], vector<string> words, int rows, int cols) {
   
    vector<pair<int,int> > positions = vector<pair<int,int> >(words.size());
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            
            for(int w=0; w<words.size(); w++) {
                string word = words[w];
                if(strncmp(word.c_str(), "", 1) == 0)  {
                    //cout << "Already found word " << endl;
                    continue;
                }

                
                //cout << "Checking for word " << word << endl;

                if(grid[i][j] == word[0]) {

                    //Searching right
                    int scan = 0;
                    int tmp = 0;
                    for(scan=j; tmp<word.size() && scan<cols; scan++, tmp++) {
                      //  cout << "Comparing char " << grid[scan][j] << " with char " << word[tmp] << endl;
                        if(!(grid[i][scan] == word[tmp])) break;
                    }
                    if(tmp == word.size()) {
                      //  cout << "Found word " << word << endl;  
                        positions[w] = make_pair(i+1, j+1);
                        words[w] = "";
                        continue;
                    }

                    //Searching up
                    tmp = 0;
                    for(scan=i; tmp<word.size() && scan>=0; scan--, tmp++) {
//cout << "Comparing char " << grid[scan][j] << " with char " << word[tmp] << endl;
                        if(!(grid[scan][j] == word[tmp])) break;
                    }
                    if(tmp == word.size()) {
                       // cout << "Found word " << word << endl;  
                        positions[w] = make_pair(i+1, j+1);
                        words[w] = "";
                        continue;
                    }

                    //Searching up-right
                    tmp = 0;
                    int scan2 = 0;
                    for(scan=i, scan2=j; tmp<word.size() && scan>=0 && scan2<cols; scan--, scan2++, tmp++) {
                       // cout << "Comparing char " << grid[scan][j] << " with char " << word[tmp] << endl;
                        if(!(grid[scan][scan2] == word[tmp])) break;
                    } 
                    if(tmp == word.size()) {
                       // cout << "Found word " << word << endl;  
                        positions[w] = make_pair(i+1, j+1);
                        words[w] = "";
                        continue;
                    }

                    //Searching up-left
                    tmp = 0;
                    for(scan=i, scan2=j; tmp<word.size() && scan>=0 && scan2>=0; scan--, scan2--, tmp++) {
                       // cout << "Comparing char " << grid[scan][j] << " with char " << word[tmp] << endl;
                        if(!(grid[scan][scan2] == word[tmp])) break;
                    } 
                    if(tmp == word.size()) {
                        //cout << "Found word " << word << endl;  
                        positions[w] = make_pair(i+1, j+1);
                        words[w] = "";
                        continue;
                    }

                    //Searching down
                    tmp = 0;
                    for(scan=i; tmp<word.size() && scan<rows; scan++, tmp++) {
                        //cout << "Comparing char " << grid[scan][j] << " with char " << word[tmp] << endl;
                        if(!(grid[scan][j] == word[tmp])) break;
                    }
                    if(tmp == word.size()) {
                       // cout << "Found word " << word << endl;  
                       positions[w] = make_pair(i+1, j+1); 
                        words[w] = "";
                        continue;
                    }

                    //Searching down-right
                    tmp = 0;
                    for(scan=i, scan2=j; tmp<word.size() && scan<rows && scan2<cols; scan++, scan2++, tmp++) {
                       // cout << "Comparing char " << grid[scan][scan2] << " with char " << word[tmp] << endl;
                        if(!(grid[scan][scan2] == word[tmp])) break;
                    }
                    if(tmp == word.size()) {
                        //cout << "Found word " << word << endl;  
                       positions[w] = make_pair(i+1, j+1);
                        words[w] = "";
                        continue;
                    }

                    //Searching down-left
                    tmp = 0;
                    for(scan=i, scan2=j; tmp<word.size() && scan<rows && scan2>=0; scan++, scan2--, tmp++) {
                       // cout << "Comparing char " << grid[scan][j] << " with char " << word[tmp] << endl;
                        if(!(grid[scan][scan2] == word[tmp])) break;
                    }
                    if(tmp == word.size()) {
                       // cout << "Found word " << word << endl;  
                        positions[w] = make_pair(i+1, j+1);
                        words[w] = "";
                        continue;
                    }

                    //Searching left
                    tmp = 0;
                    for(scan=j; tmp<word.size() && scan>=0; scan--, tmp++) {
                        //cout << "Comparing char " << grid[scan][j] << " with char " << word[tmp] << endl;
                        if(!(grid[i][scan] == word[tmp])) break;
                    }
                    if(tmp == word.size()) {
                        //cout << "Found word " << word << endl;  
                        positions[w] = make_pair(i+1, j+1);
                        words[w] = "";
                        continue;
                    }

                }
            }

        }
    }

    for(int i=0; i<positions.size(); i++) {
        cout << positions[i].first << " " << positions[i].second << endl;
    }

}

int main(void) {

    int cases;
    int t=0;
    cin >> cases;

    while(cases--) {
        if(t++) cout << endl;
        int rows, cols;
        cin >> rows >> cols;

        //cout << "rows " << rows << " cols " << cols << endl;
        char grid[52][52];
        for(int r=0; r<rows; r++) {
           string str;
           cin >> str;
           for(int i=0; i<cols; i++) {
                grid[r][i] = tolower(str[i]);
           }
        }

        int k;
        cin >> k;
        //cout << "# words " << k << endl;
        vector<string> words = vector<string>();

        for(int w = 0; w<k; w++) {
            string str;
            cin >> str;
            for(int i=0; i<str.size(); i++) {
                str[i] = tolower(str[i]);
            }
            words.push_back(str);
        }

        /*cout << "Grid" << endl;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        
        cout << "\nWords" << endl;
        for(int i=0; i<words.size(); i++) {
            cout << words[i] << endl;
        }*/

        findWords(grid, words, rows, cols);

    }

    return 0;
}
