/* 
 * File:   DRUIDEOI.cpp
 * Author: rakesh
 *
 * Created on 12 August, 2015, 3:43 PM
 */

#include <iostream>
#include<stack>
#include <stdio.h>
using namespace std;

int main() {
    int test, i, num, val;
    int data[100003], data_left[100003], data_right[100003], temp_array[100003], start , j, start2, temp_array2[100003];

    scanf("%d",&test);
    while (test--) {
        scanf("%d",&num);
        stack<int> save;
        data[0] = 0;
        temp_array[0] = 0;
        start = 1;
        for (i = 1; i <= num; i++) {
            scanf("%d",&data[i]);
            if (data[temp_array[start - 1]] < data[i]) {
                temp_array[start++] = i;
            }
            while (!save.empty() && data[save.top()] <= data[i]) {
                save.pop();
            }
            if (save.empty()) {
                data_left[i] = -1;
            } else {
                data_left[i] = save.top();
            }
            save.push(i);
            //      cout << i << " " << data_left[i] << endl;
        }
        //      cout << endl;
        stack<int> save2;
        temp_array2[num + 1] = 0;
        start2 = num;
        for (i = num; i >= 1; i--) {
            if (data[temp_array2[start2 + 1]] < data[i]) {
                temp_array2[start2--] = i;
            }
            while (!save2.empty() && data[save2.top()] <= data[i]) {
                save2.pop();
            }
            if (save2.empty()) {
                data_right[i] = -1;
                for (j = 1; j < start; j++) {
                    if (temp_array[j] >= i) {
                        break;
                    }
                    if (data[temp_array[j]] > data[i]) {
                        data_right[i] = temp_array[j];
                        break;
                    }
                }

            } else {
                data_right[i] = save2.top();
            }
            save2.push(i);
            //      cout << i << " " << data_right[i] << endl;

        }
        for (i = 1; i <= num; i++) {
            if (data_left[i] == -1) {
                for (j = num; j > start2; j--) {
                    if (temp_array2[j] <= i) {
                        break;
                    }
                    if (data[temp_array2[j]] > data[i]) {
                        data_left[i] = temp_array2[j];
                        break;
                    }
                }
            }
            printf("%d %d\n",data_left[i],data_right[i]);
        }
        //  cout << endl;

    }
    return 0;
}