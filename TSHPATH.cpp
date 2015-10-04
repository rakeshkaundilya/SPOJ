/* 
 * File:   SHPATH.cpp
 * Author: rakesh
 *
 * Created on 19 August, 2015, 5:37 PM
 */

#include <iostream>
#include <limits>
#include <string>
#include <stdio.h>
#include <list>
#include <map>
#include <limits.h>
using namespace std;

#define INF LONG_MAX-200001
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);

void scanint(int &x) {
    register int c = gc();
    x = 0;
    int neg = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = gc());
    if (c == '-') {
        neg = 1;
        c = gc();
    }
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if (neg) x = -x;
}

inline void writeInt(long int n) {
    long int N = n, rev, count = 0;
    rev = N;
    if (N == 0) {
        pc('0');
        pc('\n');
        return;
    }
    while ((rev % 10) == 0) {
        count++;
        rev /= 10;
    } //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) {
        rev = (rev << 3) + (rev << 1) + N % 10;
        N /= 10;
    } //store reverse of N in rev
    while (rev != 0) {
        pc(rev % 10 + '0');
        rev /= 10;
    }
    while (count--) pc('0');
    pc('\n');
}

map<string, int> data;

int weight[10001][10001];
long int len_set[10001],min_val;
bool visited[10001];

list<int> *graph;
list<int>::iterator it;
int main() {
    int test, i, src, cities, neigh, j, k,dest, cost, num_path, min_index;
    string name, first, second;
    scanint(test);
    while (test--) {
        scanint(cities);
        graph = new list<int>[cities + 1];
        for (src = 1; src <= cities; src++) {
            
            cin>>name;
          
            data[name] = src;
            scanint(neigh);
            for (j = 0; j < neigh; j++) {
                scanint(dest);
                scanint(cost);
                graph[src].push_back(dest);
                graph[dest].push_back(src);
                weight[src][dest] = cost;
                weight[dest][src] = cost;
            }
        }
        scanint(num_path);
        while (num_path--) {
            cin >> first>>second;
            src = data[first];
            dest = data[second];
           
            for (i = 0; i <= cities; i++) {
                len_set[i] = INF;
                visited[i] = false;
            }
            len_set[src] = 0;
            while (true) {
                min_val = INF;
                min_index = -1;
                for (i = 1; i <= cities; i++) {
                    if (!visited[i] && len_set[i] < min_val) {
                        min_val = len_set[i];
                        min_index = i;
                    }
                }
                if (min_index == -1 || min_index == dest) {
                    break;
                }
                visited[min_index] = true;
                for (it = graph[min_index].begin(); it != graph[min_index].end(); ++it) {
                    if (!visited[*it] && len_set[*it] > ((long int)weight[min_index][*it]) + len_set[min_index]) {
                        len_set[*it] = ((long int)weight[min_index][*it]) + len_set[min_index];
                    }
                }
            }
            writeInt(len_set[dest]); // << endl;
            //printf("%ld\n",len_set[dest]);
        }
        data.clear();
    }
    return 0;
}

