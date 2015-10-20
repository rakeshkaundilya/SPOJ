/* 
 * File:   AGGRCOW.cpp
 * Author: Rakesh
 *
 * Created on 15 June, 2015, 2:07 PM
 */

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
#define INF LONG_MAX
long int *data;
int main() {
    long int stalls, cows, test, i, low, high, mid,  total, max_cows, last;
    cin>>test;
    while (test--) {
        cin >> stalls>>cows;
        data = new long int[stalls + 1];
        low = INF;
        high = 0;
        for (i = 0; i < stalls; i++) {
            cin >> data[i];
        }
        sort(data, data + stalls);
        for (i = 0; i < stalls - 1; i++) {
            low = min(data[i + 1] - data[i], low);
        }
        high = data[stalls - 1] - data[0];
        while (low < high) {
            mid = low + (high - low + 1) / 2;
    //        cout<<"low: "<<low<<" high: "<<high<<" mid: "<<mid<<endl;
            total = 0;
            max_cows = 1;
            last = data[0];
            for (i = 1; i < stalls; i++) {
                if (data[i] - last >= mid) {
                    max_cows++;
       //             cout<<"i: "<<i<<" value: "<<data[i]<<" last: "<<last<<endl;
                    last = data[i];
                } else {
                    // data[i] - last < mid -> assumtion
                }
            }
     //        cout << "mid: " << mid << " " << max_cows << endl;
            if (max_cows < cows) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        cout << low << endl;

    }
    return 0;
}

