/* 
 * File:   CSTREET.cpp
 * Author: rakesh
 *
 * Created on 19 August, 2015, 2:37 PM
 */

#include <iostream>
#include <list>
using namespace std;
#define INF 889999999

int weight[1001][1001], num, len_set[1001];
list<int> *graph;
list<int>::iterator it;
bool visited[1001]; // = {0};

int main() {
    int i, test, price, edges, src, len, dest, result, min_val, min_index;
    cin>>test;
    while (test--) {
        cin >> price >> num>>edges;
        graph = new list<int>[num + 1];
        for (i = 0; i < edges; i++) {
            cin >> src >> dest>>len;
            graph[src].push_back(dest);
            graph[dest].push_back(src);
            weight[src][dest] = len;
            weight[dest][src] = len;
        }
        for (i = 0; i <= num; i++) {
            len_set[i] = INF;
            visited[i] = false;
        }
        len_set[1] = 0;

        while (true) {
            min_val = INF;
            min_index = -1;
            for (i = 1; i <= num; i++) {
                if (!visited[i] && len_set[i] < min_val) {
                    min_val = len_set[i];
                    min_index = i;
                }
            }
            if (min_index == -1) {
                break;
            }
            visited[min_index] = true;
            for (it = graph[min_index].begin(); it != graph[min_index].end(); ++it) {
                if (!visited[*it] && len_set[*it] > weight[*it][min_index]) {
                    len_set[*it] = weight[*it][min_index];
                }
            }
        }
        result = 0;
        for (i = 1; i <= num; i++) {
            result += len_set[i]; //<<" ";
        }
        cout << result * price << endl;
    }
    return 0;
}

