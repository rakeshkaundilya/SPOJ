/* 
 * File:   CRDS.cpp
 * Author: root
 *
 * Created on September 7, 2014, 2:06 AM
 */

#include <iostream>

using namespace std;

int main() {
    int test;
    unsigned long long int num;
    cin>>test;
    while(test--){
        cin>>num;
       cout<<((num*(3*num+1))/2)%1000007<<endl;
    }

    return 0;
}

