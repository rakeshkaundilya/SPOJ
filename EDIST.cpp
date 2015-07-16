/* 
 * File:   EDIST.cpp
 * Author: root
 *
 * Created on September 6, 2014, 3:01 AM
 */

#include <iostream>
#include<string>
using namespace std;
string a, b;
int *data;

int minop(int m, int n) {

    if (m == -1)
        return n + 1;
    if (n == -1)
        return m + 1;
    if (data[2001 * m + n])
        return data[2001 * m + n];
    int lefts = minop(m - 1, n) + 1;
    int rights = minop(m, n - 1) + 1;
    int cneters = minop(m - 1, n - 1) + (a[m] != b[n]);
    return data[2001 * m + n] = min(lefts, min(rights, cneters));
}

int dp(int size1,int size2) {
    int i,j;
    int data[size1 + 2][size2 + 2];

    for (i = 0; i <= size2; i++)
        data[0][i] = i;

    for (i = 0; i <= size1; i++)
        data[i][0] = i;

    for (i = 1; i <= size1; i++) {
        for (j = 1; j <= size2; j++) {
            data[i][j] = min(min(data[i - 1][j], data[i][j - 1]) + 1, data[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    }
    cout << data[size1][size2] << endl;
}

int main() {
    int test, size1, size2;
    //string a, b;
    cin>>test;
    while (test--) {
        cin >> a>>b;
        size1 = a.size();
        size2 = b.size();
        data = new int[2001 * size1 + size2];
        cout << minop(size1 - 1, size2 - 1) << endl;
    }
    return 0;
}