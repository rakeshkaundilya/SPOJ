/* 
 * File:   COINS.cpp
 * Author: rakesh
 *
 * Created on 3 July, 2014, 4:37 PM
 */

#include <iostream>
#include<map>
using namespace std;
map<long long int ,long long int>store;

long long int breakcoin(long long int coin) {
    if (coin <= 3) return coin;
    long long int first, second, third, total;
    if (store[coin]) return store[coin];
    first = coin / 2;
    if (!store[first])
        store[first] = breakcoin(first);

    second = coin / 3;
    if (!store[second])
        store[second] = breakcoin(second);

    third = coin / 4;
    if (!store[third])
        store[third] = breakcoin(third);

    //total = first + second + third;
    store[coin] = max(coin, store[first] + store[second] + store[third]);
    return store[coin];
    
    // return total=breakcoin(first)+breakcoin(second)+breakcoin(third);
    //  }
    //else
    //  return coin;
}

int main() {

    long long int coin, dollar;

    while (cin >> coin) {
        dollar = breakcoin(coin);
        cout << dollar << endl;
    }
    return 0;
}

