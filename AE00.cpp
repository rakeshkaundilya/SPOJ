/* 
 * File:   AE00.cpp
 * Author: rakesh
 * a single integer equal to the number of different rectangles that Byteman can form using his squares.
 * Created on 3 July, 2014, 1:41 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() {

    int sq,r,c=2,total=0;
    cin >> sq;
    
    for(r=0;c>1;r++) {
    
        c=sq/(r+1) - r;
        
        total= total + c;
    
    }
    cout << total<<endl;
    return 0;
}

