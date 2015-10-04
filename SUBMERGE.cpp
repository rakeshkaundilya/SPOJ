/* 
 * File:   SUBMERGE.cpp
 * Author: rakesh
 * ACCEPTED
 * Created on 22 August, 2015, 6:55 PM
 */

#include <iostream>
#include <list>

using namespace std;
#define INF 34548835

list<int> *graph;
bool *art_point;
int *parent, *disc, *low, dtime;

void dfs(int start, bool visited[]) {
    ++dtime;
    visited[start] = true;
    disc[start] = low[start] = dtime;
    int total = 0;
    list<int>::iterator it;
    for (it = graph[start].begin(); it != graph[start].end(); ++it) {
        if (!visited[*it]) {
            total++;
            parent[*it] = start;
            visited[*it] = true;
            dfs(*it, visited);
        //    cout << "u: " << start << " v: " << *it << " low[u]: " << low[start] << " low[v]: " << low[*it] << endl;
            low[start] = min(low[start], low[*it]);

            if (parent[start] == INF && total > 1) {
                art_point[start] = true;
            }

            if (parent[start] != INF && low[*it] >= disc[start]) {
                art_point[start] = true;
            }
        } else if (*it != parent[start]) {
         //   cout << "else: u: " << start << " v: " << *it << " low[u]: " << low[start] << " low[v]: " << low[*it] << endl;
       //     cout << "else: u: " << start << " v: " << *it << " low[u]: " << low[start] << " disc[v]: " << disc[*it] << endl;

            low[start] = min(low[start], disc[*it]);
        }
    }
}

int main() {
    int num, edges, i, src, dest, num_art;
    bool *visited;
    cin >> num>>edges;
    while (num || edges) {
        graph = new list<int>[num + 1];
        num_art = 0;
        art_point = new bool[num + 1];
        parent = new int[num + 1];
        disc = new int[num + 1];
        low = new int[num + 1];
        visited = new bool[num + 1];

        for (i = 0; i <= num; i++) {
            visited[i] = false;
            art_point[i] = false;
            parent[i] = disc[i] = low[i] = INF;
        }
        for (i = 0; i < edges; i++) {
            cin >> src>>dest;
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }
        dtime = 0;
        dfs(1, visited);
        for (i = 1; i <= num; i++) {
            if (art_point[i]) {
                num_art++;
            }
        }
        cout << num_art << endl;
        cin >> num>>edges;
    }
    return 0;
}

