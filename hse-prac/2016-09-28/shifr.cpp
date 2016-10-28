#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    string garbage;
    vector<vector<bool> > table(n, vector<bool> (n));
    for (int i = 0; i < n; i++) {
        getline(cin, garbage);
        for (char c : garbage) {
            table[i][j] = c == ' ';
        }
    }
    string text;
    getline(cin, text);

    vector<vector<char> > ans(n, vector<char> (n));
    
    int curr = 0;
    for (int i = 0; i < 4; i++) {
        rotate(table);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (tabe
            }
        }
    }

}   

