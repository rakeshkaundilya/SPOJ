/* 
 * File:   HANGOVER.cpp
 * Author: rakesh
 *
 * Created on 4 July, 2014, 2:23 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    float c;
    cin >> c;
    
    while (c) {

        int cards=1;
        float sum = 0;
        for (; cards; cards++) {
            sum = sum + 1 / (float)(cards + 1);
            if (sum >= c) {
                cout << cards << " card(s)" << endl;
                break;
            }
        }
        cin>>c;
    }
    return 0;
}

