/* 
 * File:   UCV2013H.cpp
 * Author: rakesh
 *
 * Created on 28 August, 2015, 10:31 PM
 */

#include <iostream>
#include <stack>
#include <map>
using namespace std;
#define FACT 10000
map<int, int> data;
map<int, int>::iterator it;

int main() {
    int i, j, rows, cols, temp, num, temp_i, temp_j, solution;
    cin >> rows>>cols;
    while (rows || cols) {
        bool oil[rows + 2][cols + 2];
        for (i = 0; i <= rows + 1; i++) {
            for (j = 0; j <= cols + 1; j++) {
                if (i == 0 || j == 0 || i == rows + 1 || j == cols + 1) {
                    oil[i][j] = false;
                    continue;
                }
                cin >> oil[i][j];
            }
        }
        stack<int> save;
        solution = 0;
        for (i = 1; i <= rows; i++) {
            for (j = 1; j <= cols; j++) {
                if (oil[i][j] == true) {
                    num = 1;
                    oil[i][j] = false;
                    save.push(i * FACT + j);
                    while (!save.empty()) {
                        temp = save.top();
                        save.pop();
                        temp_i = temp / FACT;
                        temp_j = temp % FACT;
                     //   cout<<"temp_i: "<<temp_i<<" temp_j: "<<temp_j<<endl;
                        if (oil[temp_i - 1][temp_j] == true) {
                            oil[temp_i - 1][temp_j] = false;
                            num++;
                            save.push((temp_i - 1) * FACT + temp_j);
                        }
                        if (oil[temp_i + 1][temp_j] == true) {
                            oil[temp_i + 1][temp_j] = false;
                            save.push((temp_i + 1) * FACT + temp_j);
                            num++;
                        }
                        if (oil[temp_i][temp_j - 1] == true) {
                            oil[temp_i][temp_j - 1] = false;
                            save.push(temp_i * FACT + temp_j - 1);
                            num++;
                        }
                        if (oil[temp_i][temp_j + 1] == true) {
                            oil[temp_i][temp_j + 1] = false;
                            save.push(temp_i * FACT + temp_j + 1);
                            num++;
                        }
                    }
                    data[num]++;
                 //   cout<<"i: "<<i<<" j: "<<j<<"num: "<<num<<endl;
                    solution++;
                }
            }
        }
        cout << solution << endl;
        for (it = data.begin(); it != data.end(); ++it) {
            cout << it->first << " " << it->second << '\n';
        }
        data.clear();
        cin >> rows>>cols;
    }
    return 0;
}

