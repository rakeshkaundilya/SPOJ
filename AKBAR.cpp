/* 
 * File:   AKBAR.cpp
 * Author: rakesh
 * Accepted
 * Created on 18 August, 2015, 11:54 PM
 */

#include <iostream>
#include <stdio.h>
#include <list>
#include <queue>
using namespace std;
bool visited[1000010], safe;
int strength[1000010], org_strength[1000010];
list<int> *graph;
queue<int> save;

int main() {
    int test, src, dest, i, nodes, edges, soldier, number, strn, org, temp;
    scanf("%d", &test);

    while (test--) {
        scanf("%d %d %d", &nodes, &edges, &soldier);
        graph = new list<int>[nodes + 1];
        for (i = 0; i <= nodes; i++) {
            visited[i] = false;
            strength[i] = -1;
            org_strength[i] = -1;
        }
        for (i = 0; i < edges; i++) {
            scanf("%d %d", &src, &dest);
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }
        for (i = 0; i < soldier; i++) {
            scanf("%d %d", &number, &strn);
            strength[number] = strn;
            org_strength[number] = strn;
        }
        save.push(1);
        visited[1] = true;
        while (!save.empty()) {
            org = save.front();
            save.pop();
            list<int>::iterator it;
            for (it = graph[org].begin(); it != graph[org].end(); ++it) {
                temp = *it;
                if (!visited[temp]) {
                    save.push(temp);
                }
                visited[temp] = true;
                if (strength[org] < strength[temp] - 1 && org_strength[org] == -1) {
                    strength[org] = strength[temp] - 1;
                }
                if (org_strength[temp] == -1) {
                    strength[temp] = max(strength[temp], strength[org] - 1);
                }
                //strength[temp] = max(strength[temp], strength[org] - 1);
            }
        }
        safe = true;
        for (i = 1; i <= nodes; i++) {
            // cout << "i: " << i << " strn: " << strength[i] << endl;
            if (strength[i] < 0) {
                safe = false;
                break;
            }
        }
        printf("%s\n",safe ? "Yes" : "No");
    }

    return 0;
}

