#include <bits/stdc++.h>
using namespace std;
void LSR(int graph[][6], int dist[], bool finalize[]) {
    for (int i = 0; i < 6; i++) {
        int min = INT_MAX;
        for (int k = 0; k < 6; k++) {
            if (dist[k] < min && !finalize[k]){
                min = k;
            }
        }
        finalize[min] = true;
        for (int j = 0; j < 6; j++) {
            if (j != min && graph[min][j] != -1 && ((graph[min][j] + dist[min]) < dist[j])){
                dist[j] = graph[min][j] + dist[min];
            }
        }
    }
}
int main() {
    cout << "LINK STATE ROUTING ALGORITHM \n";
    int graph[6][6] = {
        {0, 2, 5, 1, -1, -1},
        {2, 0, 3, 2, -1, -1},
        {5, 3, 0, 3, 1, 5},
        {1, 2, 3, 0, 1, -1},
        {-1, -1, 1, 1, 0, 2},
        {-1, -1, 5, -1, 2, 0}
    };
    int dist[6] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    bool finalize[6] = {false, false, false, false, false, false};
    int source, destination;
    cout << "\nEnter Source : ";
    cin >> source;
    cout << "\nEnter Destination : ";
    cin >> destination;
    dist[source] = 0;
    LSR(graph, dist, finalize);
    cout << "\nThe Shortest Distance Between " << source << " and " << destination<< " is : " << dist[destination]<< endl;
    return 0;
}
