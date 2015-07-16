/* 
 * File:   PT07Y.cpp
 * Author: rakesh
 *
 * Created on 24 November, 2014, 9:45 AM
 */

#include <iostream>
#include <list>
using namespace std;

int main() {
    int nodes, edge, u, v, s, traversed = 0;
    cin >> nodes >> edge;
    list<int> listdata[nodes], queue;
    while (edge--) {
        cin >> u>>v;
        listdata[u - 1].push_back(v - 1);
    }
    bool visited[nodes], tree = true;
    queue.push_back(0);
    list<int>::iterator it;
    for (int i = 0; i < nodes; i++)
        visited[i] = false;
    visited[0] = true;
    while (!queue.empty()) {
        s = queue.front();
        traversed++;
        queue.pop_front();
        for (it = listdata[s].begin(); it != listdata[s].end(); it++) {
            if (!visited[*it]) {
                visited[*it] = true;
                queue.push_back(*it);
            } else {
                tree = false;
                queue.clear();
                break;
            }

        }
    }
    if (tree && traversed == nodes) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

