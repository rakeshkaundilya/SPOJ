/* 
 * File:   HASHIT.cpp
 * Author: rakesh
 *
 * Created on 17 October, 2015, 12:31 PM
 */

#include <iostream>
#include <list>
#include <string>
#include<cstdio>
#include <map>
using namespace std;

#define MOD 101
#define SIZE 101
#define TRIALS 19

int hash_key(string val) {
    int hash_val = 0, size, i;
    size = val.size();
    for (i = 0; i < size; i++) {
        hash_val = (hash_val + ((int) val[i])*(i + 1)) % MOD;
    }
    return (19 * hash_val) % MOD;
}
map<string, int> save;
map<string, int>::iterator it;

int main() {
    int num, i, test, st_key, j, temp_key, size;
    cin>>test;
    string input, org_input;
    while (test--) {
        cin>>num;
        string hash[SIZE + 1];
        for (i = 0; i <= SIZE; i++) {
            hash[i] = "";
        }
        getchar();
        for (i = 0; i < num; i++) {
            getline(cin,org_input);
            input = org_input[4];
            size = org_input.size();
            for (j = 5; j < size; j++) {
                input += org_input[j];
            }
            if (org_input[0] == 'A') {

                st_key = hash_key(input);
                if (save.count(input)) {
                    // key already exists
                    continue;
                }
                for (j = 0; j <= TRIALS; j++) {
                    temp_key = (st_key + j * j + 23 * j) % MOD;

                    if (hash[temp_key] == "") {
                        hash[temp_key] = input;
                        save[input] = temp_key;
                       break;
                    }
                }
            } else {
               if (save.count(input)) {
                    hash[save[input]] = "";
                    save.erase(input);
                }
            }

        }
        cout << save.size() << endl;
        for (i = 0; i <= SIZE; i++) {
            if (hash[i] != "") {
                cout << i << ":" << hash[i] << endl;
            }
        }
        save.clear();

    }
    return 0;
}

