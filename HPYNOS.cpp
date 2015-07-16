/* 
 * File:   HPYNOS.cpp
 * Author: root
 *
 * Created on September 6, 2014, 9:18 AM
 */

#include <iostream>
#include<map>
using namespace std;
map<int, int> rep;
int a = 0,total;

int breaker(int num) {
    if (rep[num])
        return 0;
    if(num==1)
        return a;
    rep[num] = a++;
    total=0;
    while (num) {
        total = total + (num % 10)*(num % 10);
        num = num / 10;
    }
    breaker(total);

}

int main() {
    int num,val;
    cin>>num;
    if(val=breaker(num))
        cout<<val<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}
