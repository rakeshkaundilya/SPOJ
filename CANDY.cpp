/* 
 * File:   CANDY.cpp
 * Author: rakesh
 *
 * Created on 3 July, 2014, 1:17 AM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() {

    int packet;
    cin >> packet;

    while (packet + 1) {
        int candy[packet], p, moves = 0, sum = 0, eachp;

        for (p = 0; p < packet; p++) {
            cin >> candy[p];
            sum = sum + candy[p];
        }
        if (sum % packet == 0) {

            eachp = sum / packet;

            for (p = 0; p < packet; p++) {
                if (candy[p] > eachp) {

                    moves = moves + (candy[p] - eachp);

                }
            }
            cout << moves << endl;
        }
        else
            cout << "-1" << endl;
        cin >> packet;
    }

    return 0;
}

