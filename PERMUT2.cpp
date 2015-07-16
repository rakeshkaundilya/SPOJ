/* 
 * File:   PERMUT2.cpp
 * Author: rakesh
 *
 * Created on 6 July, 2014, 12:51 PM
 */

#include <iostream>

using namespace std;

int main() {
    int num;
    cin>>num;
    while (num) {
        int  r, p=0;
        int list[num+1];
        for (r = 1; r <= num; r++) {
            cin >> list[r];
        }
        for(r=1;r<=num;r++){
            if(list[list[r]]==r){
                if(r==num)
                    p=1;
            }
            else
                break;
        }
        if(p)
            cout<<"ambiguous"<<endl;
        else
             cout<<"not ambiguous"<<endl;
           

        cin>>num;
    }
    return 0;
}

