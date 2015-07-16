#include <iostream>
#include<math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t) {
        int a, c, l;
        long long int b;
        cin >> a >> b;
        if (a >= 10)
            a = a % 10;
        
        c = b % 4;
        
        if(c == 0)
            c=4;
        l = pow(a, c);
        
        if(b==0)
            cout << "1"<<endl;
        else if (l >= 10)
            cout << (l % 10) << endl;
        else
            cout << l << endl;
        
        t--;
    }
    return 0;
}