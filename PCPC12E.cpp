/* 
 * File:   PCPC12E.cpp
 * Author: rakesh
 *
 * Created on 11 August, 2015, 2:30 PM
 */

#include <iostream>
#include <queue>
using namespace std;
#define INF 999999
int moves[10001], steps[10001], blocks;
bool visited[10001];

int min_moves() {
    int org, temp, j;
    queue<int> save;
    save.push(0);
    visited[0] = true;
    steps[0] = 0;
    while (!save.empty()) {
        org = save.front();
        
       // cout<<"Node: "<<org<<" steps: "<<steps[org]<<endl;
        if(org == blocks) {
            break;
        }
        save.pop();
        for (j = 1; j <= 6; j++) {
            temp = org + j;
            if (temp > blocks) {
                break;
            }
            if (!visited[temp]) {
                visited[temp] = true;
                if (moves[temp] > 0) {
                    while(moves[moves[temp]] > 0) {
                        visited[temp] = true;
                        temp = moves[temp];
                    }
                    steps[moves[temp]] = min(steps[moves[temp]], steps[org] + 1);
                    save.push(moves[temp]);
                    visited[moves[temp]] = true;
                } else {
                    steps[temp] = min(steps[org] + 1,steps[temp]);
                    save.push(temp);
                }
            }
        }
    }
    return steps[blocks];
}

int main() {
    int len, wid, snakes, ladders, i, j, src, dest,solution;
    while (cin >> len >> wid >> snakes >> ladders) {
        blocks = len*wid;
        for (i = 0; i <= blocks; i++) {
            moves[i] = 0;
            steps[i] = INF;
            visited[i] = false;
        }
        for (i = 0; i < snakes; i++) {
            cin >> src>>dest;
            moves[src] = dest;
        }
        for (i = 0; i < ladders; i++) {
            cin >> src>>dest;
            moves[src] = dest;
        }
        solution = min_moves();
        if(solution == INF) {
            solution = -1;
        }
        cout<<solution<<endl;
    }
    return 0;
}

