/* 
 * File:   LABYR1.cpp
 * Author: rakesh
 *
 * Created on 20 October, 2015, 1:09 AM
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char input[1010][1010];
int rows, cols, data[1010][1010], max_len;
bool visited[1010][1010];

int dfs(int i, int j, int present) {
    //  cout<<"i: "<<i<<" j: "<<present<<endl;
    visited[i][j] = true;
    for (int m = 1; m >= -1; m--) {
        for (int n = 1; n >= -1; n--) {
            if (abs(m) != abs(n) && !(i + m >= rows || j + n >= cols || i + m < 0 || j + n < 0)) {
                if (!visited[i + m][j + n] && input[i + m][j + n] == '.') {
                    data[i][j] = max(data[i][j], dfs(i + m, j + n, max(present, data[i][j]) + 1) + 1);
                }
            }
        }
    }
    max_len = max(max_len, present);
    return data[i][j];
}

int main() {
    int test, i, j, m, n;
    string temp_input;
    cin>>test;
    while (test--) {
        //cout<<"Test: "<<test<<endl;
        cin >> cols>>rows;
       // cout<<"Rows: "<<rows<<" cols: "<<cols<<endl;
        for (i = 0; i < rows; i++) {
            cin>>temp_input;
            for (j = 0; j < cols; j++) {
                input[i][j] = temp_input[j];
                visited[i][j] = false;
                data[i][j] = 0;
            }
        }
        
        max_len = 0;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (input[i][j] == '.' && !visited[i][j]) {
                    dfs(i, j, 0);
                }
            }
        }
        cout << "Maximum rope length is " << max_len << "." << endl;

    }
    return 0;
}

