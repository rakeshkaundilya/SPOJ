/* 
 * File:   RAINBOW.cpp
 * Author: rakesh
 *
 * Created on 29 August, 2015, 12:53 AM
 */

#include <iostream>
#include <list>
#include <stack>
using namespace std;
list<int> *graph;
stack<int> save;
bool *visited;
int *weight, *values, **data, *members;
list<int>::iterator it;

int main() {
    int num, i, j, max_wt, num_likes, result, src, dest, count, temp, total_wt, num_members;
    cin >> num>>max_wt;
    while (num && max_wt) {
        graph = new list<int>[num + 1];
        weight = new int[num + 1];
        visited = new bool[num + 1];
        values = new int[num + 1];
        data = new int*[max_wt + 1];
        members = new int[num + 1];
        for (i = 1; i <= num; i++) {
            cin >> weight[i];
            visited[i] = false;
            values[i] = 0;
        }
        for (i = 0; i <= max_wt; i++) {
            data[i] = new int[max_wt + 1];
        }
        for (src = 1; src <= num; src++) {
            cin>>num_likes;
            for (i = 0; i < num_likes; i++) {
                cin>>dest;
                graph[src].push_back(dest);
                graph[dest].push_back(src);
            }
        }
        count = 1;
        for (i = 1; i <= num; i++) {
            if (!visited[i]) {
                save.push(i);
                total_wt = weight[i];
                visited[i] = true;
                num_members = 1;
                while (!save.empty()) {
                    temp = save.top();
                    save.pop();
                    for (it = graph[temp].begin(); it != graph[temp].end(); ++it) {
                        if (!visited[*it]) {
                            total_wt += weight[*it];
                            save.push(*it);
                            num_members++;
                            visited[*it] = true;
                        }
                    }
                }
                members[count] = num_members;
                values[count++] = total_wt;
            }
        }
        
        for (i = 1; i <= max_wt; i++) {
            for (j = 1; j < count; j++) {
                if (i >= values[j]) {
                    data[i][j] = max(data[i][j-1],data[i - values[j]][j - 1] + members[j]);
                } else {
                    data[i][j] = data[i][j-1];
                }
            }
        }
        cout << data[max_wt][count-1] << endl;
        cin >> num>>max_wt;
    }
    return 0;
}

