/*
 * File:   BITMAP.cpp
 * Author: rakesh
 *  not accepted till now
 * Created on 5 December, 2014, 10:33 PM
 */
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int rows, cols, *input, *output;
bool *covered;
#define INF 32432

int count(int i, int j) {

    if (output[200 * i + j] != INF) return output[200 * i + j];
    covered[200 * i + j] = true;

    if (input[200 * i + j] == 1) {
        output[200 * i + j] = 0;
    }
    for (int m = 1; m >= -1; m--) {
        for (int n = 1; n >= -1; n--) {
            if (abs(m) != abs(n) && !(i + m >= rows || j + n >= cols || i + m < 0 || j + n < 0)) {
                if (!covered[200 * (i + m) + j + n]) {
                    output[200 * i + j] = min(output[200 * i + j], count(i + m, j + n) + 1);
                } else if (output[200 * (i + m) + j + n] != INF) {
                    output[200 * i + j] = min(output[200 * i + j], output[200 * (i + m) + j + n] + 1);
                }
            }
        }
    }
    // covered[200 * i + j] = false;
    return output[200 * i + j];
}

int main() {
    int test, i, j;
    cin>>test;
    while (test--) {
        cin >> rows >> cols;
        input = new int[201 * rows + cols];
        output = new int[201 * rows + cols];
        covered = new bool[201 * rows + cols];
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                scanf("%1d", &input[200 * i + j]);
                output[200 * i + j] = INF;
                covered[200 * i + j] = false;
            }
        }
        //covered[0] = true;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (covered[200 * i + j] == false) {
                    count(i, j);
                }
            }
        }
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                for (int m = 1; m >= -1; m--) {
                    for (int n = 1; n >= -1; n--) {
                        if (abs(m) != abs(n) && !(i + m >= rows || j + n >= cols || i + m < 0 || j + n < 0)) {
                            output[200 * i + j] = min(output[200 * i + j], output[200 * (i + m) + j + n] + 1);
                        }
                    }
                }
            }
        }
        // int x = count(0,0);
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                cout << output[200 * i + j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

