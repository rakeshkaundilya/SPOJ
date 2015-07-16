/* 
 * File:   CANDY3.cpp
 * Author: rakesh
 *
 * Created on 3 July, 2014, 2:10 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() {

    int test;
    cin >> test;
    long long int child;
    while (test) {
        cin >> child;
        long long int candy, p, total = 0;
        for (p = 0; p < child; p++) {
            cin >> candy;
            total = total + candy;
            total=total%child;
        }
        if (total == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        test--;
    }

    return 0;
}

