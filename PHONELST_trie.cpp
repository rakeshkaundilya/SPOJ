/* 
 * File:   PHONELST_trie.cpp
 * Author: Rakesh
 *
 * Created on 22 July, 2015, 2:17 PM
 */

#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct Node * NODE;
int i;

struct Node {
    bool end;
    NODE child[10];

    Node() {
        for (i = 0; i < 10; i++) child[i] = NULL;
        end = false;
    }

};

int main() {
    int test, num, i, trie_val, size;
    string value;
    bool consis, this_num_exists;
    NODE root, pointer; //= new Node;
    cin>>test;
    while (test--) {
        consis = true;

        cin>>num;
        root = new Node;
        while (num--) {
            cin>>value;
            size = value.size();

            this_num_exists = true;
            if (consis) {
                pointer = root;
                for (i = 0; i < size; i++) {
                    trie_val = value[i] - '0';
                    //cout<<trie_val<<endl;
                    if ((pointer->child[trie_val]) != NULL) {
                        if ((pointer->child[trie_val])->end) {
                            consis = false;
                            break;
                        }
                    } else {
                        pointer->child[trie_val] = new Node;
                        pointer->child[trie_val]->end = (i == size - 1 ? true : false);
                        this_num_exists = false;
                    }
                    pointer = pointer->child[trie_val];
                }
                if (this_num_exists) {
                    consis = false;
                }
            }
        }
        free(root);
        cout << (consis ? "YES" : "NO") << endl;
    }
    return 0;
}