/* 
 * File:   ESCJAILA.cpp
 * Author: rakesh
 *
 * Created on 19 October, 2015, 11:19 PM
 */

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct tuplea TUPLE;

struct tuplea {
    int row, col, door;
};
#define INF 99999999

int main() {
    int rows, cols, i, j, start_i, start_j, m, n, min_esc, door;
    string temp_input;
    cin >> rows >> cols;
    while (rows != -1) {
        char input[rows][cols];
        bool visited[rows][cols][2];
        int dist[rows][cols][2];
        for (i = 0; i < rows; i++) {
            cin>>temp_input;
            for (j = 0; j < cols; j++) {
                input[i][j] = temp_input[j];
                if (input[i][j] == 'H') {
                    start_i = i;
                    start_j = j;
                    input[i][j] = '.';
                }
                visited[i][j][0] = visited[i][j][1] = false;
                dist[i][j][0] = dist[i][j][1] = INF;
            }
        }
        TUPLE tuple;
        tuple.row = start_i;
        tuple.col = start_j;
        tuple.door = 0;
        dist[start_i][start_j][0] = 0;
        visited[start_i][start_j][0] = true;
        queue<TUPLE> save;
        save.push(tuple);
        min_esc = INF;
        while (!save.empty()) {
            tuple = save.front();
            save.pop();
            i = tuple.row;
            j = tuple.col;
            door = tuple.door;
            for (m = 1; m >= -1; m--) {
                for (n = 1; n >= -1; n--) {
                    if (abs(m) != abs(n) && !(i + m >= rows || j + n >= cols || i + m < 0 || j + n < 0)) {
                        if (!visited[i + m][j + n][door]) {
                            tuple.row = i + m;
                            tuple.col = j + n;
                            tuple.door = -1;
                            if (input[i + m][j + n] == 'O') {
                                tuple.door = 1;
                            } else if (input[i + m][j + n] == 'C') {
                                tuple.door = 0;
                            } else if (input[i + m][j + n] == 'D' && door == 1) {
                                tuple.door = door;
                            } else if (input[i + m][j + n] == '.') {
                                tuple.door = door;
                            }
                            if (tuple.door != -1) {
                                save.push(tuple);
      //                          cout<<"i: "<<i+m<<" "<<j+n<<" door: "<<tuple.door<<endl;
                                dist[i + m][j + n][tuple.door] = dist[i][j][door] + 1;
                                visited[i + m][j + n][tuple.door] = true;
                            }
                            visited[i + m][j + n][door] = true;
                        }
                    } else if (abs(m) != abs(n)) {
                        // Over the edge
                        if ((input[i][j] == 'O')
                                || (input[i][j] == 'C')
                                || (input[i][j] == 'D' && door == 1)
                                || (input[i][j] == '.')
                                ) {
                            min_esc = min(min_esc, dist[i][j][door] + 1);
                        }
                    }
                }
            }
        }
        cout<<(min_esc != INF ? min_esc : -1)<<endl;
        cin >> rows >> cols;
    }
    return 0;
}