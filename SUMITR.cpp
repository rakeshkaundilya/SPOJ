// Accepted.. Except #include<iostream>,put others in one line. Remove spaces. Then size will be less than 228KB
#include <iostream>
using namespace std;
main() {
    long int t, v, n, i, j, a, d[101][101] = {0};
    cin>>t;
    while (t--) {
        cin>>n;
        v = 0;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i; j++) {
                cin>>a;
                d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + a;
                v = max(v, d[i][j]);
            }
        }
        cout << v << endl;
    }
}