/* 
 * File:   TREEORD.cpp
 * Author: rakesh
 *
 * Created on 26 August, 2015, 12:52 PM
 */

#include <iostream>

using namespace std;
int total = 1;
int *rev_in, *actual_post, num;

void get_post(int in[], int start, int end, int pre[], int pre_start, int pre_end) {
   // cout << "in_s: " << start << " in_e: " << end << " pre_s: " << pre_start << " pre_e: " << pre_end << endl;
    if (start < 0 || end > num || start > end || pre_start < 0 || pre_end > num || pre_start > pre_end || total>num) {
        return;
    }
    if (start == end) {
        actual_post[total++] = in[start];
        return;
    }
    int mid_index = rev_in[pre[pre_start]];
//    cout << "mid_index: " << mid_index << endl;
    if (mid_index != start) {
        get_post(in, start, mid_index - 1, pre, pre_start + 1, pre_start + (mid_index - start));
    }
    if (mid_index != end) {
        get_post(in, mid_index + 1, end, pre, pre_start + (mid_index - start) + 1, pre_end);
    }
    actual_post[total++] = in[mid_index];
    return;
}

int main() {
    int i;
    bool result;
    cin>>num;
    int pre[num + 1], post[num + 1], in[num + 1];
    rev_in = new int[num + 1];
    actual_post = new int[num + 1];
    for (i = 1; i <= num; i++) {
        cin >> pre[i];
    }
    for (i = 1; i <= num; i++) {
        cin >> post[i];
    }
    for (i = 1; i <= num; i++) {
        cin >> in[i];
        rev_in[in[i]] = i;
    }
    get_post(in, 1, num, pre, 1, num);
    result = true;
    for (i = 1; i <= num; i++) {
        if(post[i] !=actual_post[i]){
            result = false;
            break;
        }
    }
    if (result) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}

