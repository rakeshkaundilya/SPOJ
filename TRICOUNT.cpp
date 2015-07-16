/* 
 * File:   TRICOUNT.cpp
 * Author: rakesh
 *
 * Created on 8 July, 2014, 11:13 AM
 */

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        long long int total;
        total = (long long int)n * (n + 2)*(2*n + 1) / 8;
        cout << total << endl;
    }
    return 0;
}

