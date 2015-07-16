#include<iostream>
#include<stdio.h>
using namespace std;

/*
 * 
 */
int main() {

    int t;
    cin >> t;
    while (t) {

        int n;
        cin >> n;

        int male[n], female[n], p, q, ml, fl, th = 0, a, b;
        getchar();
        for (p = 0; p < n; p++)
            cin >> male[p];
        getchar();
        for (p = 0; p < n; p++)
            cin >> female[p];

        for (p = 0; p < n; p++) {

            ml = fl = '\0';

            for (q = 0; q < n; q++) {

                if (ml < male[q]) {
                    ml = male[q];
                  //  cout << ml << endl;
                    a = q;
                }

                if (fl < female[q]) {
                    fl = female[q];
                    b = q;
                }
            }

            //  if((ml!='\0')&&(fl!='\0'))
            th = th + ml*fl;
            //cout << ml << endl;
            male[a] = '\0';
            female[b] = '\0';

        }

        cout << th << endl;
        t--;
    }

    return 0;
}

