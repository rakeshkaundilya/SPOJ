/* 
 * File:   BISHOPS.cpp
 * Author: rakesh
 *Accepted
 * Created on 10 August, 2014, 6:35 PM
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
string n, m ;
    while (getline(cin,n)) {
        m="";
        int size = n.size(), val, rem = 0, sub = 1;
        
        if (size == 1 && n[0] <= 49) {
            cout << n[0]-48 << endl;
            continue;
        }
        for (int i = size - 1; i >= 0; i--) {
            val = n[i] - 48 - sub;
            sub = 0;
            if (val < 0) {
                m = (char) (val + 58) + m;
                --n[i - 1];
            } else {
                m = (char) (val + 48) + m;
            }
        }
        n = m;
        m="";
        for (int i = size - 1; i >= 0; i--) {
            val = 2 * (n[i] - 48) + rem;
            rem = 0;
            if (val >= 10) {
                m = (char) (val % 10 + 48) + m;
                rem = 1;
            } else
                m = (char) (val + 48) + m;
        }
        if (rem)
            m = (char) (rem + 48) + m;

        cout << m << endl;


    }
    return 0;
}
