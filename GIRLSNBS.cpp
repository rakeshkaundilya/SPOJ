/* 
 * File:   GIRLSNBS.cpp
 * Author: rakesh
 * Solved
 * Created on 24 November, 2014, 1:29 PM
 */

#include <iostream>

using namespace std;

int main() {
    int girls, boys, max, min, arrange;
    cin >> girls>>boys;
    while (girls + 1 || boys + 1) {
        max = girls > boys ? girls : boys;
        min = girls < boys ? girls : boys;
         if (max % (min + 1) == 0)
            arrange = max / (min + 1);
        else
            arrange = (max / (min + 1)) + 1;

        cout << arrange << endl;

        cin >> girls>>boys;

    }
    return 0;
}

