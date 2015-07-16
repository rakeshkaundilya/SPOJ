/* 
 * File:   ACPC10A.cpp
 * Author: rakesh
 *
 * Created on 3 July, 2014, 2:06 AM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    
    int first,second,third;
    cin >> first >> second >> third;
    while(first||second||third){

        if((second-first)==(third-second))
            cout << "AP "<< (2*third-second)<<endl;
        else
            cout << "GP "<< ((third*second)/first)<<endl;
    
        cin >> first >> second >> third;
    }
    
    return 0;
}

