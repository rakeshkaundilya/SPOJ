/* 
 * File:   HOMO.cpp
 * Author: rakesh
 *
 * Created on 27 August, 2015, 9:43 PM
 */

#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
#define FACT 10000000000
#define MOD 1000000001

map<long long int, int> data;
map<long long int, bool> save;

int main() {
    long long int opern, value, temp, highest;
    char type[10];
    bool homo, hetro;
    cin>>opern;
    while (opern--) {
        scanf("%s %lld", type, &value);
        value += MOD;
        homo = false;
        hetro = false;
        if (type[0] == 'i') {
            data[value]++;
            temp = data[value];
            save[temp * FACT + value] = true;
            if (temp > 1) {
                save.erase((temp - 1) * FACT + value);
            }

        } else {
            if (data[value] > 0) {
                if (data[value] == 1) {
                    save.erase(FACT + value);
                    data.erase(value);
                } else {
                    data[value]--;
                    temp = data[value];
                    save[temp * FACT + value] = true;
                    save.erase((temp + 1) * FACT + value);
                }
            }
        }
        if (!save.empty() && !data.empty()) {
            highest = save.rbegin()->first;
            highest = highest / FACT;
        } else {
            highest = 0;
        }
        if (highest > 1) {
            homo = true;
        }
        if (save.size() > 1 && data.size() > 1) {
            hetro = true;
        }
        if (homo && hetro) {
            printf("both\n"); // << endl;
        } else if (homo && !hetro) {
            printf("homo\n");
        } else if (!homo && hetro) {
            printf("hetero\n");
        } else {
            printf("neither\n");
        }
    }
    return 0;
}

