/* 
 * File:   SMILEY1807.cpp
 * Author: rakesh
 *
 * Created on 23 August, 2015, 4:29 PM
 */

#include <iostream>
#include <string>
using namespace std;
int one[1000001],eightenn[1000001],oneeighty[1000001], eighteenoseven[1000001];

int main() {
    int i, size;
    string input;
    cin>>input;
    size = input.size();
    one[0] = eighteenoseven[0] = oneeighty[0] = eightenn[0] = 0;
    for (i = 1; i <= size; i++) {
        if (input[i - 1] == '1') {
            one[i] = one[i - 1] + 1;
        } else {
            one[i] = one[i - 1];
        }
        if (input[i - 1] == '8' && one[i - 1] > 0) {
            eightenn[i] = max(one[i - 1], eightenn[i - 1]) + 1;
        } else {
            eightenn[i] = eightenn[i - 1];
        }
        if (input[i - 1] == '0' && eightenn[i - 1] > 0) {
            oneeighty[i] = max(eightenn[i - 1], oneeighty[i - 1]) + 1;
        } else {
            oneeighty[i] = oneeighty[i - 1];
        }
        if (input[i - 1] == '7' && oneeighty[i - 1] > 0) {
            eighteenoseven[i] = max(eighteenoseven[i - 1], oneeighty[i - 1]) + 1;
        } else {
            eighteenoseven[i] = eighteenoseven[i - 1];
        }
    }
    cout << eighteenoseven[size] << endl;
    return 0;
}

