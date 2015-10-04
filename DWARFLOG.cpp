/* 
 * File:   DWARFLOG.cpp
 * Author: rakesh
 * THink about fixing height and keeping index as the variable quantity in Segment tree.
 * Now if for a given range of height, if we can get the range i.e max and min value of indexes and
 *  that is equal to difference of height that implies heights heights indexes are consequent
 * ***ACCEPTED****
 * Created on 16 August, 2015, 7:27 PM
 */

#include <iostream>

using namespace std;
typedef struct Node * NODE;

struct Node {
    int max_val;
    int min_val;
    int lrange;
    int urange;
    NODE left;
    NODE right;
};
int num, *data,*height;

NODE getnode(int val) {
    NODE main = new Node;
    main->max_val = val;
    main->min_val = val;
    main->left = NULL;
    main->right = NULL;
    main->lrange = 0;
    main->urange = 0;
    return main;
}

NODE store_segment(int left, int right, NODE * pointer) {
    if (left == right) {
        NODE main = getnode(data[left]);
        main->lrange = left;
        main->urange = left;
        return main;
    }
    int mid = (left + right) / 2;
    NODE left_part = store_segment(left, mid, pointer);
    NODE right_part = store_segment(mid + 1, right, pointer);
    (*pointer) = getnode(max(left_part->max_val, right_part->max_val));
    
    (*pointer)->min_val = min(left_part->min_val, right_part->min_val);
    
    (*pointer)->left = left_part;
    (*pointer)->right = right_part;
    (*pointer)->lrange = left;
    (*pointer)->urange = right;
    //cout << (*pointer)->lrange << " " << (*pointer)->urange << "    " << (*pointer)->sum << endl;
    return (*pointer);
}

void get_max_min(int low, int up, NODE pointer, int *max_val, int *min_val) {
    if (pointer->lrange == low && pointer->urange == up) {
        *max_val = pointer->max_val;
        *min_val = pointer->min_val;
        return;
    } else if (low == up) {
        *max_val = data[low];
        *min_val = data[low];
        return;
    }
    int mid = (pointer->lrange + pointer->urange) / 2;
    //cout<<mid<<endl;
    if (up > mid && low <= mid) {
        get_max_min(low, mid, pointer->left, max_val, min_val);
        int temp_max = *max_val;
        int temp_min = *min_val;
        get_max_min(mid + 1, up, pointer->right, max_val, min_val);
        int current_max = *max_val;
        int current_min = *min_val;
        if(current_max > temp_max) {
            *max_val = current_max;
        } else {
            *max_val = temp_max;
        }
        if(current_min < temp_min) {
            *min_val = current_min;
        } else {
            *min_val = temp_min;
        }
        return;
    } else if (up <= mid && low <= mid) {
        get_max_min(low, up, pointer->left, max_val, min_val);
    } else if (low > mid && up > mid) {
        get_max_min(low, up, pointer->right, max_val, min_val);
    }
    return ;
}

void update_value(NODE pointer, int i, int val) {
    if (pointer != NULL) {

        if (pointer->lrange == pointer->urange) {
            pointer->max_val = val;
            pointer->min_val = val;
            data[i] = val;
            return;
        }

        int mid = (pointer->lrange + pointer->urange) / 2;
        if (i <= mid) {
            update_value(pointer->left, i, val);
        } else {
            update_value(pointer->right, i, val);
        }
        pointer->max_val = max(pointer->left->max_val, pointer->right->max_val);
        pointer->min_val = min(pointer->left->min_val, pointer->right->min_val);
        return;
    }
}

int main() {
    int i, query, type, left, right, result, temp, reqd, max_val, min_val;
    cin >> num>>query;
    data = new int[num + 1];
    for (i = 1; i <= num; i++) {
        data[i] = i;
    }
    
    NODE root;
    store_segment(1, num, &root);
    while (query--) {
        cin >> type >> left>>right;
        if (type == 1) {
            temp = data[left];
            update_value(root, left, data[right]);
            update_value(root, right, temp);
        } else {
            max_val = 0;
            min_val = 99999999;
            get_max_min(left, right, root, &max_val, &min_val);
            
            if (max_val - min_val == right - left) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            //cout << result << endl;
        }
    }

    return 0;
}

