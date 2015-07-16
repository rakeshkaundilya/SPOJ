/* 
 * File:   WILLITST.cpp
 * Author: rakesh
 *
 * Created on 17 July, 2014, 5:29 PM
 */

#include <iostream>

using namespace std;

int main() {
    int a=1;
    long long int n;
    cin>>n;
    while (n > 1) {
        if (n % 2 == 0){
            n = n / 2;
        }
        else{
            n = 3 *(n+1);
            cout<<"NIE"<<endl;
            a=0;
            break;
        }
    }
    if(a)
        cout<<"TAK"<<endl;
    return 0;
}

