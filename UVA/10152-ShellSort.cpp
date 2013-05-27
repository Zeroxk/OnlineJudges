#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;

struct Turtle {
    string name;
    int pos;
};

int main(void) {
    int cases;
    cin >> cases;

    while(cases--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Turtle> origOrder;

        for(int i=0; i<n; i++) {
            string str;
            getline(cin, str);
            Turtle t = {str, 0};
            origOrder.push_back(t);
        }


        /*for(int i=0; i<origOrder.size(); i++) {
            cout << origOrder[i] << endl;
        }
        cout << endl;*/

        vector<string> desiredVec;
        map<string, int> desiredMap;
        for(int i=0; i<n; i++) {
            string str;
            getline(cin, str);
            desiredVec.push_back(str);
            desiredMap[str] = i;
        }

        for(int i=0; i<origOrder.size(); i++) {
            Turtle* t = &origOrder[i];
            t->pos = desiredMap[t->name];
        }

        int max = -1;
        int maxNotInOrder = -1;
        for(int i=0; i<origOrder.size(); i++) {

            if(origOrder[i].pos > max) {
                max = origOrder[i].pos;
            }else if(origOrder[i].pos > maxNotInOrder) {
                maxNotInOrder = origOrder[i].pos;
            }

        }

        //cout << "Max is " << max << endl;
        //cout << "Max not in order is " << maxNotInorder << endl;

        for(int i=maxNotInOrder; i>=0; i--) {
            cout << desiredVec[i] << endl;
        }
        
        cout << endl;

    }

    return 0;
}
