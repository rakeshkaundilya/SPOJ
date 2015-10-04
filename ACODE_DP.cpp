/* 
 * File:   ACODE_DP.cpp
 * Author: rakesh
 * Accepted
 * Created on 30 July, 2015, 11:04 AM
 */

#include <iostream>
#include<string>
using namespace std;
unsigned long int **data, i, j, size, current, prev;

int main() {
    string input;
    cin>>input;
    while (input != "0") {
        size = input.size();
        data = new unsigned long int*[size + 1];
        for (i = 0; i <= size; i++) {
            data[i] = new unsigned long int[2];
        }
        data[0][0] = 1;
        data[1][0] = 1;
        data[1][1] = 0;
        for (i = 2; i <= size; i++) {
            current = input[i - 1] - '0';
            prev = input[i - 2] - '0';
            if (current != 0) {
                data[i][0] = data[i - 1][0] + data[i - 1][1];
            } else {
                data[i][0] = 0;
            }
            if (prev * 10 + current <= 26 && prev!=0) {
                data[i][1] = data[i - 2][0] + data[i - 2][1];
            } else {
                data[i][1] = 0;
            }
        }
        cout << data[size][0] + data[size][1] << endl;
        cin>>input;
    }
    return 0;
}

