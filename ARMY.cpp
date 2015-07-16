/* 
 * File:   ARMY.cpp
 * Author: rakesh
 *
 * Created on 17 July, 2014, 3:49 PM
 */

#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int t, r, g, m, p, q,a=0;
    cin>>t;
    while (t--) {
        cin >> g>>m;
        int ng[g], nm[m];
        for (r = 0; r < g; r++)
            cin >> ng[r];
        for (r = 0; r < m; r++)
            cin >> nm[r];
        sort(ng, ng + g);
        sort(nm, nm + m);
        for (p = 0, q = 0; p < g || q < m; p++, q++) {
            if (ng[p] >= nm[q]) {
                nm[q] = 0;
                if (q == m - 1) {
                    cout << "Godzilla" << endl;
                    a=1;
                    break;
                }
                p--;
            } else {
                if (p == g - 1) {
                    cout << "MechaGodzilla" << endl;
                    a=1;
                    break;
                }
                q--;
            }
        }
        if(!a)
            cout<<"uncertain"<<endl;
       
        }
    return 0;
}

