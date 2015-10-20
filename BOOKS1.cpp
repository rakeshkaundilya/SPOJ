/* 
 * File:   BOOKS1.cpp
 * Author: rakesh
 *
 * Created on 17 October, 2015, 5:27 PM
 */

#include <iostream>
#include <limits.h>
#include <stack>
using namespace std;
stack<long int> save;

int main() {
    long int num, test, scribe, i, j, temp_val, low, high, mid, required, total;
    long int *pages;
    cin>>test;
    while (test--) {
        cin >> num>>scribe;
        pages = new long int[num + 1];
        low = 0;
        high = 0;
        for (i = 1; i <= num; i++) {
            cin >> pages[i];
            low = max(low, pages[i]);
            high += pages[i];
        }
        while (low < high) {
            mid = low + (high - low) / 2;
            required = 1;
            total = 0;
            for (i = num; i > 0; i--) {
                if (total + pages[i] <= mid) {
                    total += pages[i];
                } else {
                    total = pages[i];
                    required++;
                }
            }
            if (required <= scribe) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
      //  cout << low << endl;
        total = 0;
        required = 1;
        for (i = num; i > 0; i--) {
            if (total + pages[i] > low || scribe - required == i) {
                total = pages[i];
                required++;
                save.push(-1);
                save.push(pages[i]);
            } else {
                total += pages[i];
                save.push(pages[i]);
            }
        }
        while(!save.empty()) {
            temp_val = save.top();
            save.pop();
            if(temp_val == -1) {
                cout<<"/ ";
            } else {
                cout<<temp_val<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

